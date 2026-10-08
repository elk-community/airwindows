/*
*	File:		FastDistance.cpp
*	
*	Version:	1.0
* 
*	Created:	9/3/26
*	
*	Copyright:  Copyright © 2026 Airwindows, Airwindows uses the MIT license
* 
*	Disclaimer:	IMPORTANT:  This Apple software is supplied to you by Apple Computer, Inc. ("Apple") in 
*				consideration of your agreement to the following terms, and your use, installation, modification 
*				or redistribution of this Apple software constitutes acceptance of these terms.  If you do 
*				not agree with these terms, please do not use, install, modify or redistribute this Apple 
*				software.
*
*				In consideration of your agreement to abide by the following terms, and subject to these terms, 
*				Apple grants you a personal, non-exclusive license, under Apple's copyrights in this 
*				original Apple software (the "Apple Software"), to use, reproduce, modify and redistribute the 
*				Apple Software, with or without modifications, in source and/or binary forms; provided that if you 
*				redistribute the Apple Software in its entirety and without modifications, you must retain this 
*				notice and the following text and disclaimers in all such redistributions of the Apple Software. 
*				Neither the name, trademarks, service marks or logos of Apple Computer, Inc. may be used to 
*				endorse or promote products derived from the Apple Software without specific prior written 
*				permission from Apple.  Except as expressly stated in this notice, no other rights or 
*				licenses, express or implied, are granted by Apple herein, including but not limited to any 
*				patent rights that may be infringed by your derivative works or by other works in which the 
*				Apple Software may be incorporated.
*
*				The Apple Software is provided by Apple on an "AS IS" basis.  APPLE MAKES NO WARRANTIES, EXPRESS OR 
*				IMPLIED, INCLUDING WITHOUT LIMITATION THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY 
*				AND FITNESS FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND OPERATION ALONE 
*				OR IN COMBINATION WITH YOUR PRODUCTS.
*
*				IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL OR CONSEQUENTIAL 
*				DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS 
*				OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, 
*				REPRODUCTION, MODIFICATION AND/OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED AND WHETHER 
*				UNDER THEORY OF CONTRACT, TORT (INCLUDING NEGLIGENCE), STRICT LIABILITY OR OTHERWISE, EVEN 
*				IF APPLE HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/
/*=============================================================================
	FastDistance.cpp
	
=============================================================================*/
#include "FastDistance.h"


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

COMPONENT_ENTRY(FastDistance)


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	FastDistance::FastDistance
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
FastDistance::FastDistance(AudioUnit component)
	: AUEffectBase(component)
{
	CreateElements();
	Globals()->UseIndexedParameters(kNumberOfParameters);
	SetParameter(kParam_A, kDefaultValue_ParamA );
         
#if AU_DEBUG_DISPATCHER
	mDebugDispatcher = new AUDebugDispatcher (this);
#endif
	
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	FastDistance::GetParameterValueStrings
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult			FastDistance::GetParameterValueStrings(AudioUnitScope		inScope,
                                                                AudioUnitParameterID	inParameterID,
                                                                CFArrayRef *		outStrings)
{
        
    return kAudioUnitErr_InvalidProperty;
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	FastDistance::GetParameterInfo
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult			FastDistance::GetParameterInfo(AudioUnitScope		inScope,
                                                        AudioUnitParameterID	inParameterID,
                                                        AudioUnitParameterInfo	&outParameterInfo )
{
	ComponentResult result = noErr;

	outParameterInfo.flags = 	kAudioUnitParameterFlag_IsWritable
						|		kAudioUnitParameterFlag_IsReadable;
    
    if (inScope == kAudioUnitScope_Global) {
        switch(inParameterID)
        {
            case kParam_A:
                AUBase::FillInParameterName (outParameterInfo, kParameterAName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamA;
                break;
           default:
                result = kAudioUnitErr_InvalidParameter;
                break;
            }
	} else {
        result = kAudioUnitErr_InvalidParameter;
    }
    


	return result;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	FastDistance::GetPropertyInfo
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult			FastDistance::GetPropertyInfo (AudioUnitPropertyID	inID,
                                                        AudioUnitScope		inScope,
                                                        AudioUnitElement	inElement,
                                                        UInt32 &		outDataSize,
                                                        Boolean &		outWritable)
{
	return AUEffectBase::GetPropertyInfo (inID, inScope, inElement, outDataSize, outWritable);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	FastDistance::GetProperty
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult			FastDistance::GetProperty(	AudioUnitPropertyID inID,
                                                        AudioUnitScope 		inScope,
                                                        AudioUnitElement 	inElement,
                                                        void *			outData )
{
	return AUEffectBase::GetProperty (inID, inScope, inElement, outData);
}

//	FastDistance::Initialize
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult FastDistance::Initialize()
{
    ComponentResult result = AUEffectBase::Initialize();
    if (result == noErr)
        Reset(kAudioUnitScope_Global, 0);
    return result;
}

#pragma mark ____FastDistanceEffectKernel



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	FastDistance::FastDistanceKernel::Reset()
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void		FastDistance::FastDistanceKernel::Reset()
{	
	firstDry = firstAvg = 0.0f;
	psA = psB = psC = psD = psE = psF = psG = psH = psI = psJ = psK = psL = psM = 0.0f;
	psN = psO = psP = psQ = psR = psS = psT = psU = psV = psW = psX = psY = psZ = 0.0f;
	psa = psb = psc = psd = pse = psf = psg = psh = psi = psj = psk = psl = psm = 0.0f;
	psn = pso = psp = psq = psr = pss = pst = psu = psv = psw = psx = psy = psz = 0.0f;	
	prevDistance = 0;
	pointCycle = pointAL = pointBL = 0.0f;

	fpd = 1.0; while (fpd < 16386) fpd = rand()*UINT32_MAX;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	FastDistance::FastDistanceKernel::Process
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void		FastDistance::FastDistanceKernel::Process(	const Float32 	*inSourceP,
                                                    Float32		 	*inDestP,
                                                    UInt32 			inFramesToProcess,
                                                    UInt32			inNumChannels, 
                                                    bool			&ioSilence )
{
	UInt32 nSampleFrames = inFramesToProcess;
	const Float32 *sourceP = inSourceP;
	Float32 *destP = inDestP;
	double overallscale = 1.0;
	overallscale /= 48000.0; //we are treating both 44.1k and 48k as '1X'
	overallscale *= GetSampleRate(); //and expecting to get 2X, 4X as needed
	float pointDerez = 1.0f / overallscale; //forcing it to be simple
	
	float distance = pow(GetParameter( kParam_A )*7.28f,2.0f); //0 to 52.9984
	int distanceSteps = (int)distance; //52 maximum
	distance -= (float)distanceSteps; //0.9984
	
	while (nSampleFrames-- > 0) {
		double inputSample = *sourceP;
		if (fabs(inputSample)<1.18e-23) inputSample = fpd * 1.18e-17;

		pointCycle += pointDerez;
		if (pointCycle > 0.9999999) {
			//this is sample rate handling for the plugin, so that
			//a more primitive reverb node can run at any rate.
			
			//begin just the distance filter part
			firstDry = inputSample; //start by doing the interpolation
			inputSample += firstAvg; inputSample *= 0.5f; firstAvg = inputSample;
			inputSample = (firstDry*(1.0f-distance)) + (inputSample*distance);
			//having done at least one interpolation we can now do the integer number of stages
			if (prevDistance < distanceSteps) {
				switch (prevDistance)
				{
					case  0: psA = inputSample; //if we've changed the setting
					case  1: psB = inputSample; //reset the ones being put back into play
					case  2: psC = inputSample; //this won't be happening constantly,
					case  3: psD = inputSample; //but since we don't have an array
					case  4: psE = inputSample; //this is the structure by which we
					case  5: psF = inputSample; //get the new averagings going
					case  6: psG = inputSample; //without pops or clicks
					case  7: psH = inputSample;
					case  8: psI = inputSample;
					case  9: psJ = inputSample;
					case 10: psK = inputSample;
					case 11: psL = inputSample;
					case 12: psM = inputSample;
					case 13: psN = inputSample;
					case 14: psO = inputSample;
					case 15: psP = inputSample;
					case 16: psQ = inputSample;
					case 17: psR = inputSample;
					case 18: psS = inputSample;
					case 19: psT = inputSample;
					case 20: psU = inputSample;
					case 21: psV = inputSample;
					case 22: psW = inputSample;
					case 23: psX = inputSample;
					case 24: psY = inputSample;
					case 25: psZ = inputSample;
					case 26: psa = inputSample;
					case 27: psb = inputSample;
					case 28: psc = inputSample;
					case 29: psd = inputSample;
					case 30: pse = inputSample;
					case 31: psf = inputSample;
					case 32: psg = inputSample;
					case 33: psh = inputSample;
					case 34: psi = inputSample;
					case 35: psj = inputSample;
					case 36: psk = inputSample;
					case 37: psl = inputSample;
					case 38: psm = inputSample;
					case 39: psn = inputSample;
					case 40: pso = inputSample;
					case 41: psp = inputSample;
					case 42: psq = inputSample;
					case 43: psr = inputSample;
					case 44: pss = inputSample;
					case 45: pst = inputSample;
					case 46: psu = inputSample;
					case 47: psv = inputSample;
					case 48: psw = inputSample;
					case 49: psx = inputSample;
					case 50: psy = inputSample;
					case 51: psz = inputSample;
					case 52: prevDistance = distanceSteps;
				}
			}
			switch (52-distanceSteps)
			{ //apply the stack of filter steps to produce the distance filter
				case  0: inputSample += psz; inputSample *= 0.5; psz = inputSample;
				case  1: inputSample += psy; inputSample *= 0.5; psy = inputSample;
				case  2: inputSample += psx; inputSample *= 0.5; psx = inputSample;
				case  3: inputSample += psw; inputSample *= 0.5; psw = inputSample;
				case  4: inputSample += psv; inputSample *= 0.5; psv = inputSample;
				case  5: inputSample += psu; inputSample *= 0.5; psu = inputSample;
				case  6: inputSample += pst; inputSample *= 0.5; pst = inputSample;
				case  7: inputSample += pss; inputSample *= 0.5; pss = inputSample;
				case  8: inputSample += psr; inputSample *= 0.5; psr = inputSample;
				case  9: inputSample += psq; inputSample *= 0.5; psq = inputSample;
				case 10: inputSample += psp; inputSample *= 0.5; psp = inputSample;
				case 11: inputSample += pso; inputSample *= 0.5; pso = inputSample;
				case 12: inputSample += psn; inputSample *= 0.5; psn = inputSample;
				case 13: inputSample += psm; inputSample *= 0.5; psm = inputSample;
				case 14: inputSample += psl; inputSample *= 0.5; psl = inputSample;
				case 15: inputSample += psk; inputSample *= 0.5; psk = inputSample;
				case 16: inputSample += psj; inputSample *= 0.5; psj = inputSample;
				case 17: inputSample += psi; inputSample *= 0.5; psi = inputSample;
				case 18: inputSample += psh; inputSample *= 0.5; psh = inputSample;
				case 19: inputSample += psg; inputSample *= 0.5; psg = inputSample;
				case 20: inputSample += psf; inputSample *= 0.5; psf = inputSample;
				case 21: inputSample += pse; inputSample *= 0.5; pse = inputSample;
				case 22: inputSample += psd; inputSample *= 0.5; psd = inputSample;
				case 23: inputSample += psc; inputSample *= 0.5; psc = inputSample;
				case 24: inputSample += psb; inputSample *= 0.5; psb = inputSample;
				case 25: inputSample += psa; inputSample *= 0.5; psa = inputSample;
				case 26: inputSample += psZ; inputSample *= 0.5; psZ = inputSample;
				case 27: inputSample += psY; inputSample *= 0.5; psY = inputSample;
				case 28: inputSample += psX; inputSample *= 0.5; psX = inputSample;
				case 29: inputSample += psW; inputSample *= 0.5; psW = inputSample;
				case 30: inputSample += psV; inputSample *= 0.5; psV = inputSample;
				case 31: inputSample += psU; inputSample *= 0.5; psU = inputSample;
				case 32: inputSample += psT; inputSample *= 0.5; psT = inputSample;
				case 33: inputSample += psS; inputSample *= 0.5; psS = inputSample;
				case 34: inputSample += psR; inputSample *= 0.5; psR = inputSample;
				case 35: inputSample += psQ; inputSample *= 0.5; psQ = inputSample;
				case 36: inputSample += psP; inputSample *= 0.5; psP = inputSample;
				case 37: inputSample += psO; inputSample *= 0.5; psO = inputSample;
				case 38: inputSample += psN; inputSample *= 0.5; psN = inputSample;
				case 39: inputSample += psM; inputSample *= 0.5; psM = inputSample;
				case 40: inputSample += psL; inputSample *= 0.5; psL = inputSample;
				case 41: inputSample += psK; inputSample *= 0.5; psK = inputSample;
				case 42: inputSample += psJ; inputSample *= 0.5; psJ = inputSample;
				case 43: inputSample += psI; inputSample *= 0.5; psI = inputSample;
				case 44: inputSample += psH; inputSample *= 0.5; psH = inputSample;
				case 45: inputSample += psG; inputSample *= 0.5; psG = inputSample;
				case 46: inputSample += psF; inputSample *= 0.5; psF = inputSample;
				case 47: inputSample += psE; inputSample *= 0.5; psE = inputSample;
				case 48: inputSample += psD; inputSample *= 0.5; psD = inputSample;
				case 49: inputSample += psC; inputSample *= 0.5; psC = inputSample;
				case 50: inputSample += psB; inputSample *= 0.5; psB = inputSample;
				case 51: inputSample += psA; inputSample *= 0.5; psA = inputSample;
				case 52: break;
			}
			//end distance filter
			
			pointAL = pointBL;
			pointBL = inputSample;
			pointCycle = 0.0; //interpolation point values
			//this is the sample rate adjustment for the plugin version
			//game engine may well always run at 44.1k or whatever			
		}
		inputSample = pointAL+((pointBL-pointAL)*pointCycle);
		//this is the linear interpolation between reverb points
		//governed by sample rate, to work as a plugin
		
		//begin 32 bit floating point dither
		int expon; frexpf((float)inputSample, &expon);
		fpd ^= fpd << 13; fpd ^= fpd >> 17; fpd ^= fpd << 5;
		inputSample += ((double(fpd)-uint32_t(0x7fffffff)) * 3.553e-44l * pow(2,expon+62));
		//end 32 bit floating point dither
		
		*destP = inputSample;
		
		sourceP += inNumChannels; destP += inNumChannels;
	}
}

