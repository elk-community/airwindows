/*
*	File:		DeRez5.cpp
*	
*	Version:	1.0
* 
*	Created:	8/18/26
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
	DeRez5.cpp
	
=============================================================================*/
#include "DeRez5.h"


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

COMPONENT_ENTRY(DeRez5)


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	DeRez5::DeRez5
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
DeRez5::DeRez5(AudioUnit component)
	: AUEffectBase(component)
{
	CreateElements();
	Globals()->UseIndexedParameters(kNumberOfParameters);
	SetParameter(kParam_A, kDefaultValue_ParamA );
	SetParameter(kParam_B, kDefaultValue_ParamB );
	SetParameter(kParam_C, kDefaultValue_ParamC );
	SetParameter(kParam_D, kDefaultValue_ParamD );
	SetParameter(kParam_E, kDefaultValue_ParamE );
	SetParameter(kParam_F, kDefaultValue_ParamF );
         
#if AU_DEBUG_DISPATCHER
	mDebugDispatcher = new AUDebugDispatcher (this);
#endif
	
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	DeRez5::GetParameterValueStrings
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult			DeRez5::GetParameterValueStrings(AudioUnitScope		inScope,
                                                                AudioUnitParameterID	inParameterID,
                                                                CFArrayRef *		outStrings)
{
        
    return kAudioUnitErr_InvalidProperty;
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	DeRez5::GetParameterInfo
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult			DeRez5::GetParameterInfo(AudioUnitScope		inScope,
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
            case kParam_B:
                AUBase::FillInParameterName (outParameterInfo, kParameterBName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamB;
                break;
            case kParam_C:
                AUBase::FillInParameterName (outParameterInfo, kParameterCName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamC;
                break;
            case kParam_D:
                AUBase::FillInParameterName (outParameterInfo, kParameterDName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamD;
                break;
            case kParam_E:
                AUBase::FillInParameterName (outParameterInfo, kParameterEName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamE;
                break;
            case kParam_F:
                AUBase::FillInParameterName (outParameterInfo, kParameterFName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamF;
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
//	DeRez5::GetPropertyInfo
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult			DeRez5::GetPropertyInfo (AudioUnitPropertyID	inID,
                                                        AudioUnitScope		inScope,
                                                        AudioUnitElement	inElement,
                                                        UInt32 &		outDataSize,
                                                        Boolean &		outWritable)
{
	return AUEffectBase::GetPropertyInfo (inID, inScope, inElement, outDataSize, outWritable);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	DeRez5::GetProperty
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult			DeRez5::GetProperty(	AudioUnitPropertyID inID,
                                                        AudioUnitScope 		inScope,
                                                        AudioUnitElement 	inElement,
                                                        void *			outData )
{
	return AUEffectBase::GetProperty (inID, inScope, inElement, outData);
}

//	DeRez5::Initialize
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult DeRez5::Initialize()
{
    ComponentResult result = AUEffectBase::Initialize();
    if (result == noErr)
        Reset(kAudioUnitScope_Global, 0);
    return result;
}

#pragma mark ____DeRez5EffectKernel



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	DeRez5::DeRez5Kernel::Reset()
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void		DeRez5::DeRez5Kernel::Reset()
{
	for (int x = 0; x < bez_total; x++) {for (int y = 0; y < 2; y++) bezEQ[x][y] = 0.0;}
	pointCycle = pointAL = pointBL = 0.0; sDerez = 1.0;
	lastSampleL = 0.0; directionCountL = 1.0; goingUpL = false;
	fpd = 1.0; while (fpd < 16386) fpd = rand()*UINT32_MAX;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	DeRez5::DeRez5Kernel::Process
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void		DeRez5::DeRez5Kernel::Process(	const Float32 	*inSourceP,
                                                    Float32		 	*inDestP,
                                                    UInt32 			inFramesToProcess,
                                                    UInt32			inNumChannels, 
                                                    bool			&ioSilence )
{
	UInt32 nSampleFrames = inFramesToProcess;
	const Float32 *sourceP = inSourceP;
	Float32 *destP = inDestP;
	double overallscale = 1.0;
	overallscale /= 44100.0;
	overallscale *= GetSampleRate();
	
	double applyDerez = 1.0-pow(GetParameter( kParam_A ),2.0+overallscale);
	double trimDerez = (1.0-GetParameter( kParam_B ))*16.0*overallscale;
	double square = 1.0-pow(GetParameter( kParam_C ),3.0);
	double brightBez = (1.0-pow(GetParameter( kParam_D ),2.0))*4.0*overallscale;
	int stepped = 999999; 
	if (brightBez > 1.0) {stepped = (int)brightBez; brightBez = 0.99999999 / stepped;}
	else brightBez = 1.1;
	double brightTrim = 1.0-(brightBez*((double)stepped/(stepped+1.0)));
	double bassRef = pow(GetParameter( kParam_E ),4.0);
	double bassisBez = (bassRef*0.25) / overallscale;
	stepped = 999999; if (bassisBez > 0.000001) stepped = (int)(1.0/bassisBez);
	if (bassisBez > 0.0) bassisBez = 0.99999999 / stepped;
	double bassisTrim = 1.0-(bassisBez*((double)stepped/(stepped+1.0)));
	double output = GetParameter( kParam_F );
	
	while (nSampleFrames-- > 0) {
		double inputSampleL = *sourceP;
		if (fabs(inputSampleL)<1.18e-23) inputSampleL = fpd * 1.18e-17;
		
		if (inputSampleL > lastSampleL == goingUpL) directionCountL += (applyDerez+trimDerez);
		else directionCountL = trimDerez+1.0;
		goingUpL = (inputSampleL > lastSampleL); lastSampleL = inputSampleL;
		
		if (brightBez < 1.0){
			bezEQ[bez_HMcycle][0] += brightBez;
			bezEQ[bez_HMAL][0] += (inputSampleL * 0.5 * brightBez);
			if (bezEQ[bez_HMcycle][0] > brightTrim) {
				bezEQ[bez_HMDL][0] = bezEQ[bez_HMCL][0]; bezEQ[bez_HMCL][0] = bezEQ[bez_HMBL][0]; 
				bezEQ[bez_HMBL][0] = bezEQ[bez_HMAL][0]*(0.5-(brightBez*0.082));
				bezEQ[bez_HMAL][0] = 0.0; bezEQ[bez_HMcycle][0] = 0.0;
			}
			double X = bezEQ[bez_HMcycle][0];
			inputSampleL = bezEQ[bez_HMCL][0]+(bezEQ[bez_HMDL][0]*(1.0-X)*(1.0-X));
			inputSampleL += (bezEQ[bez_HMCL][0]*2.0*(1.0-X)*X)+(bezEQ[bez_HMBL][0]*X*X);
			inputSampleL /= brightTrim;
		}
		if (bassisBez > 0.0) {
			bezEQ[bez_LMcycle][0] += bassisBez;
			bezEQ[bez_LMAL][0] += (inputSampleL * bassisBez);
			if (bezEQ[bez_LMcycle][0] > bassisTrim) {
				bezEQ[bez_LMDL][0] = bezEQ[bez_LMCL][0]; bezEQ[bez_LMCL][0] = bezEQ[bez_LMBL][0]; 
				bezEQ[bez_LMBL][0] = bezEQ[bez_LMAL][0]*(0.5-(bassisBez*0.082));
				bezEQ[bez_LMAL][0] = 0.0; bezEQ[bez_LMcycle][0] = 0.0;
			}
			double X = bezEQ[bez_LMcycle][0];
			inputSampleL -= (bezEQ[bez_LMCL][0]+(bezEQ[bez_LMDL][0]*(1.0-X)*(1.0-X)))*0.5;
			inputSampleL -= ((bezEQ[bez_LMCL][0]*2.0*(1.0-X)*X)+(bezEQ[bez_LMBL][0]*X*X))*0.5;
			inputSampleL /= bassisTrim;
		}
		if (applyDerez+trimDerez > 0.0) {
			pointCycle += sDerez;
			if (pointCycle > 0.9999999) {
				pointAL = pointBL;
				pointBL = inputSampleL;
				pointCycle = 0.0; //waveform point values
				
				stepped = 999999;
				if (applyDerez < 0.999999) stepped = (int)(1.0/(1.0-applyDerez));
				if (stepped > directionCountL) stepped = directionCountL;
				if (stepped < 1) stepped = 1;
				sDerez = 0.99999999 / stepped;		
			}
			double X = pointCycle*square;
			if (sDerez > 0.0) {
				inputSampleL = pointAL+((pointBL-pointAL)*X);
			} else {
				inputSampleL = 0.0;
			}
		}
		if (brightBez < 1.0) {
			bezEQ[bez_HMcycle][1] += brightBez;
			bezEQ[bez_HMAL][1] += (inputSampleL * brightBez);
			if (bezEQ[bez_HMcycle][1] > brightTrim) {
				bezEQ[bez_HMDL][1] = bezEQ[bez_HMCL][1]; bezEQ[bez_HMCL][1] = bezEQ[bez_HMBL][1]; 
				bezEQ[bez_HMBL][1] = bezEQ[bez_HMAL][1]*(0.5-(brightBez*0.082));
				bezEQ[bez_HMAL][1] = 0.0; bezEQ[bez_HMcycle][1] = 0.0;
			}
			double X = bezEQ[bez_HMcycle][1];
			inputSampleL = bezEQ[bez_HMCL][1]+(bezEQ[bez_HMDL][1]*(1.0-X)*(1.0-X));
			inputSampleL += (bezEQ[bez_HMCL][1]*2.0*(1.0-X)*X)+(bezEQ[bez_HMBL][1]*X*X);
			inputSampleL /= brightTrim;
		}
		if (bassisBez > 0.0) {
			bezEQ[bez_LMcycle][1] += bassisBez;
			bezEQ[bez_LMAL][1] += (inputSampleL * bassisBez);
			if (bezEQ[bez_LMcycle][1] > bassisTrim) {
				bezEQ[bez_LMDL][1] = bezEQ[bez_LMCL][1]; bezEQ[bez_LMCL][1] = bezEQ[bez_LMBL][1]; 
				bezEQ[bez_LMBL][1] = bezEQ[bez_LMAL][1]*(0.5-(bassisBez*0.082));
				bezEQ[bez_LMAL][1] = 0.0; bezEQ[bez_LMcycle][1] = 0.0;
			}
			double X = bezEQ[bez_LMcycle][1];
			inputSampleL -= (bezEQ[bez_LMCL][1]+(bezEQ[bez_LMDL][1]*(1.0-X)*(1.0-X)))*0.5;
			inputSampleL -= ((bezEQ[bez_LMCL][1]*2.0*(1.0-X)*X)+(bezEQ[bez_LMBL][1]*X*X))*0.5;
			inputSampleL /= bassisTrim;
		}
		if (output < 1.0) inputSampleL *= output;
		
		//begin 32 bit floating point dither
		int expon; frexpf((float)inputSampleL, &expon);
		fpd ^= fpd << 13; fpd ^= fpd >> 17; fpd ^= fpd << 5;
		inputSampleL += ((double(fpd)-uint32_t(0x7fffffff)) * 3.553e-44l * pow(2,expon+62));
		//end 32 bit floating point dither
		
		*destP = inputSampleL;
		
		sourceP += inNumChannels; destP += inNumChannels;
	}
}

