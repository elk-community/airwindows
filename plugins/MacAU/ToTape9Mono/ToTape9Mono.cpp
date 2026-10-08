/*
*	File:		ToTape9Mono.cpp
*	
*	Version:	1.0
* 
*	Created:	8/18/25
*	
*	Copyright:  Copyright © 2025 Airwindows, Airwindows uses the MIT license
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
	ToTape9Mono.cpp
	
=============================================================================*/
#include "ToTape9Mono.h"


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

COMPONENT_ENTRY(ToTape9Mono)


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	ToTape9Mono::ToTape9Mono
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ToTape9Mono::ToTape9Mono(AudioUnit component)
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
	SetParameter(kParam_G, kDefaultValue_ParamG );
	SetParameter(kParam_H, kDefaultValue_ParamH );
	SetParameter(kParam_I, kDefaultValue_ParamI );
         
#if AU_DEBUG_DISPATCHER
	mDebugDispatcher = new AUDebugDispatcher (this);
#endif
	
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	ToTape9Mono::GetParameterValueStrings
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult			ToTape9Mono::GetParameterValueStrings(AudioUnitScope		inScope,
                                                                AudioUnitParameterID	inParameterID,
                                                                CFArrayRef *		outStrings)
{
        
    return kAudioUnitErr_InvalidProperty;
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	ToTape9Mono::GetParameterInfo
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult			ToTape9Mono::GetParameterInfo(AudioUnitScope		inScope,
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
            case kParam_G:
                AUBase::FillInParameterName (outParameterInfo, kParameterGName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamG;
                break;
            case kParam_H:
                AUBase::FillInParameterName (outParameterInfo, kParameterHName, false);
 				outParameterInfo.unit = kAudioUnitParameterUnit_CustomUnit;
				outParameterInfo.flags |= kAudioUnitParameterFlag_DisplayLogarithmic;
				outParameterInfo.unitName = kParameterHUnit;
				outParameterInfo.minValue = 25.0;
                outParameterInfo.maxValue = 200.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamH;
                break;
            case kParam_I:
                AUBase::FillInParameterName (outParameterInfo, kParameterIName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamI;
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
//	ToTape9Mono::GetPropertyInfo
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult			ToTape9Mono::GetPropertyInfo (AudioUnitPropertyID	inID,
                                                        AudioUnitScope		inScope,
                                                        AudioUnitElement	inElement,
                                                        UInt32 &		outDataSize,
                                                        Boolean &		outWritable)
{
	return AUEffectBase::GetPropertyInfo (inID, inScope, inElement, outDataSize, outWritable);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	ToTape9Mono::GetProperty
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult			ToTape9Mono::GetProperty(	AudioUnitPropertyID inID,
                                                        AudioUnitScope 		inScope,
                                                        AudioUnitElement 	inElement,
                                                        void *			outData )
{
	return AUEffectBase::GetProperty (inID, inScope, inElement, outData);
}

//	ToTape9Mono::Initialize
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult ToTape9Mono::Initialize()
{
    ComponentResult result = AUEffectBase::Initialize();
    if (result == noErr)
        Reset(kAudioUnitScope_Global, 0);
    return result;
}

#pragma mark ____ToTape9MonoEffectKernel



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	ToTape9Mono::ToTape9MonoKernel::Reset()
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void		ToTape9Mono::ToTape9MonoKernel::Reset()
{
	iirEncL = 0.0; iirDecL = 0.0;
	compEncL = 1.0; compDecL = 1.0;
	avgEncL = 0.0; avgDecL = 0.0;
	
	for (int temp = 0; temp < 1001; temp++) {dL[temp] = 0.0;}
	sweepL = M_PI;
	nextmaxL = 0.5;
	gcount = 0;	
	
	for (int x = 0; x < gslew_total; x++) gslew[x] = 0.0;
	
	hysteresisL = 0.0;
	
	for (int x = 0; x < 33; x++) {avg32L[x] = 0.0; post32L[x] = 0.0;}
	for (int x = 0; x < 17; x++) {avg16L[x] = 0.0; post16L[x] = 0.0;}
	for (int x = 0; x < 9; x++) {avg8L[x] = 0.0; post8L[x] = 0.0;}
	for (int x = 0; x < 5; x++) {avg4L[x] = 0.0; post4L[x] = 0.0;}
	for (int x = 0; x < 3; x++) {avg2L[x] = 0.0; post2L[x] = 0.0;}
	avgPos = 0;
	lastDarkL = 0.0;
	//preTapeHack	
		
	headBumpL = 0.0;
	for (int x = 0; x < hdb_total; x++) {hdbA[x] = 0.0;hdbB[x] = 0.0;}
	//from ZBandpass, so I can use enums with it	
	
	lastSampleL = 0.0;
	wasPosClipL = false;
	wasNegClipL = false;
	for (int x = 0; x < 17; x++) intermediateL[x] = 0.0;
	for (int x = 0; x < 33; x++) slewL[x] = 0.0;
	fpdL = 1.0; while (fpdL < 16386) fpdL = rand()*UINT32_MAX;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	ToTape9Mono::ToTape9MonoKernel::Process
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void		ToTape9Mono::ToTape9MonoKernel::Process(	const Float32 	*inSourceP,
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
	
	int spacing = floor(overallscale); //should give us working basic scaling, usually 2 or 4
	if (spacing < 1) spacing = 1; if (spacing > 16) spacing = 16;
	int slewsing = floor(overallscale*2.0);
	if (slewsing < 2) slewsing = 2; if (slewsing > 32) slewsing = 32;

	
	double inputGain = pow(GetParameter( kParam_A )*2.0,2.0);
	
	double dublyAmount = GetParameter( kParam_B )*2.0;
	double outlyAmount = (1.0-GetParameter( kParam_B ))*-2.0;
	if (outlyAmount < -1.0) outlyAmount = -1.0;
	double iirEncFreq = (1.0-GetParameter( kParam_C ))/overallscale;
	double iirDecFreq = GetParameter( kParam_C )/overallscale;
	
	double flutDepth = pow(GetParameter( kParam_D ),6)*overallscale*50;
	if (flutDepth > 498.0) flutDepth = 498.0;
	double flutFrequency = (0.02*pow(GetParameter( kParam_E ),3))/overallscale;
	double bias = (GetParameter( kParam_F )*2.0)-1.0;
	double underBias = (pow(bias,4)*0.25)/overallscale;
	double overBias = pow(1.0-bias,3)/overallscale;
	if (bias > 0.0) underBias = 0.0;
	if (bias < 0.0) overBias = 1.0/overallscale;
	
	gslew[threshold9] = overBias;
	overBias *= 1.618033988749894848204586;
	gslew[threshold8] = overBias;
	overBias *= 1.618033988749894848204586;
	gslew[threshold7] = overBias;
	overBias *= 1.618033988749894848204586;
	gslew[threshold6] = overBias;
	overBias *= 1.618033988749894848204586;
	gslew[threshold5] = overBias;
	overBias *= 1.618033988749894848204586;
	gslew[threshold4] = overBias;
	overBias *= 1.618033988749894848204586;
	gslew[threshold3] = overBias;
	overBias *= 1.618033988749894848204586;
	gslew[threshold2] = overBias;
	overBias *= 1.618033988749894848204586;
	gslew[threshold1] = overBias;
	overBias *= 1.618033988749894848204586;
	
	double headBumpDrive = (GetParameter( kParam_G )*0.1)/overallscale;
	double headBumpMix = GetParameter( kParam_G )*0.5;
	
	hdbA[hdb_freq] = GetParameter( kParam_H )/GetSampleRate();
	hdbB[hdb_freq] = hdbA[hdb_freq]*0.9375;
	hdbB[hdb_reso] = hdbA[hdb_reso] = 0.618033988749894848204586;
	hdbB[hdb_a1] = hdbA[hdb_a1] = 0.0;
	
	double K = tan(M_PI * hdbA[hdb_freq]);
	double norm = 1.0 / (1.0 + K / hdbA[hdb_reso] + K * K);
	hdbA[hdb_a0] = K / hdbA[hdb_reso] * norm;
	hdbA[hdb_a2] = -hdbA[hdb_a0];
	hdbA[hdb_b1] = 2.0 * (K * K - 1.0) * norm;
	hdbA[hdb_b2] = (1.0 - K / hdbA[hdb_reso] + K * K) * norm;
	K = tan(M_PI * hdbB[hdb_freq]);
	norm = 1.0 / (1.0 + K / hdbB[hdb_reso] + K * K);
	hdbB[hdb_a0] = K / hdbB[hdb_reso] * norm;
	hdbB[hdb_a2] = -hdbB[hdb_a0];
	hdbB[hdb_b1] = 2.0 * (K * K - 1.0) * norm;
	hdbB[hdb_b2] = (1.0 - K / hdbB[hdb_reso] + K * K) * norm;
	
	double outputGain = GetParameter( kParam_I )*2.0;
	
	while (nSampleFrames-- > 0) {
		double inputSampleL = *sourceP;
		if (fabs(inputSampleL)<1.18e-23) inputSampleL = fpdL * 1.18e-17;
		
		if (inputGain != 1.0) {
			inputSampleL *= inputGain;
		}
		
		//Dubly encode
		iirEncL = (iirEncL * (1.0 - iirEncFreq)) + (inputSampleL * iirEncFreq);
		double highPart = ((inputSampleL-iirEncL)*2.848);
		highPart += avgEncL; avgEncL = (inputSampleL-iirEncL)*1.152;
		if (highPart > 1.0) highPart = 1.0; if (highPart < -1.0) highPart = -1.0;
		double dubly = fabs(highPart);
		if (dubly > 0.0) {
			double adjust = log(1.0+(255.0*dubly))/2.40823996531;
			if (adjust > 0.0) dubly /= adjust;
			compEncL = (compEncL*(1.0-iirEncFreq))+(dubly*iirEncFreq);
			inputSampleL += ((highPart*compEncL)*dublyAmount);
		} //end Dubly encode L		
		
		//begin Flutter
		if (flutDepth > 0.0) {
			if (gcount < 0 || gcount > 999) gcount = 999;
			dL[gcount] = inputSampleL;
			int count = gcount;
			double offset = flutDepth + (flutDepth * sin(sweepL));
			sweepL += nextmaxL * flutFrequency;
			if (sweepL > (M_PI*2.0)) {
				sweepL -= M_PI*2.0;
				double flutA = 0.24 + (fpdL / (double)UINT32_MAX * 0.74);
				nextmaxL = flutA;
			}
			count += (int)floor(offset);
			inputSampleL = (dL[count-((count > 999)?1000:0)] * (1-(offset-floor(offset))));
			inputSampleL += (dL[count+1-((count+1 > 999)?1000:0)] * (offset-floor(offset)));
			gcount--;
		}
		//end Flutter
		
		//start bias routine
		if (fabs(bias) > 0.001) {
			for (int x = 0; x < gslew_total; x += 3) {
				if (underBias > 0.0) {
					double stuck = fabs(inputSampleL - (gslew[x]/0.975)) / underBias;
					if (stuck < 1.0) inputSampleL = (inputSampleL * stuck) + ((gslew[x]/0.975)*(1.0-stuck));
				}
				if ((inputSampleL - gslew[x]) > gslew[x+2]) inputSampleL = gslew[x] + gslew[x+2];
				if (-(inputSampleL - gslew[x]) > gslew[x+2]) inputSampleL = gslew[x] - gslew[x+2];
				gslew[x] = inputSampleL * 0.975;
			}
		}
		//end bias routine
		
		//begin tiny hysteresis
		double applyHysteresis = (1.0-fabs(inputSampleL))*(1.0-fabs(inputSampleL))*0.012;
		hysteresisL = fmax(fmin(hysteresisL+((inputSampleL*fabs(inputSampleL))),0.011449),-0.011449)*0.999;
		inputSampleL += (hysteresisL*applyHysteresis);
		
		//begin Left
		inputSampleL *= inputGain;
		double darkSampleL = inputSampleL;
		if (avgPos > 31) avgPos = 0;
		if (slewsing > 31) {
			avg32L[avgPos] = darkSampleL;
			darkSampleL = 0.0;
			for (int x = 0; x < 32; x++) {darkSampleL += avg32L[x];}
			darkSampleL /= 32.0;
		} if (slewsing > 15) {
			avg16L[avgPos%16] = darkSampleL;
			darkSampleL = 0.0;
			for (int x = 0; x < 16; x++) {darkSampleL += avg16L[x];}
			darkSampleL /= 16.0;
		} if (slewsing > 7) {
			avg8L[avgPos%8] = darkSampleL;
			darkSampleL = 0.0;
			for (int x = 0; x < 8; x++) {darkSampleL += avg8L[x];}
			darkSampleL /= 8.0;
		} if (slewsing > 3) {
			avg4L[avgPos%4] = darkSampleL;
			darkSampleL = 0.0;
			for (int x = 0; x < 4; x++) {darkSampleL += avg4L[x];}
			darkSampleL /= 4.0;
		} if (slewsing > 1) {
			avg2L[avgPos%2] = darkSampleL;
			darkSampleL = 0.0;
			for (int x = 0; x < 2; x++) {darkSampleL += avg2L[x];}
			darkSampleL /= 2.0; 
		} //only update after the post-distortion filter stage
		
		double avgSlewL = fmin(fabs(lastDarkL-inputSampleL)*0.12*overallscale,1.0);
		avgSlewL = 1.0-(1.0-avgSlewL*1.0-avgSlewL);
		inputSampleL = (inputSampleL*(1.0-avgSlewL)) + (darkSampleL*avgSlewL);
		lastDarkL = darkSampleL;
		
		inputSampleL = fmax(fmin(inputSampleL,2.305929007734908),-2.305929007734908);
		double addtwo = inputSampleL * inputSampleL;
		double empower = inputSampleL * addtwo; // inputSampleL to the third power
		inputSampleL -= (empower / 6.0);
		empower *= addtwo; // to the fifth power
		inputSampleL += (empower / 69.0);
		empower *= addtwo; //seventh
		inputSampleL -= (empower / 2530.08);
		empower *= addtwo; //ninth
		inputSampleL += (empower / 224985.6);
		empower *= addtwo; //eleventh
		inputSampleL -= (empower / 9979200.0f);
		//this is a degenerate form of a Taylor Series to approximate sin()
		
		darkSampleL = inputSampleL;
		if (avgPos > 31) avgPos = 0;
		if (slewsing > 31) {
			post32L[avgPos] = darkSampleL;
			darkSampleL = 0.0;
			for (int x = 0; x < 32; x++) {darkSampleL += post32L[x];}
			darkSampleL /= 32.0;
		} if (slewsing > 15) {
			post16L[avgPos%16] = darkSampleL;
			darkSampleL = 0.0;
			for (int x = 0; x < 16; x++) {darkSampleL += post16L[x];}
			darkSampleL /= 16.0;
		} if (slewsing > 7) {
			post8L[avgPos%8] = darkSampleL;
			darkSampleL = 0.0;
			for (int x = 0; x < 8; x++) {darkSampleL += post8L[x];}
			darkSampleL /= 8.0;
		} if (slewsing > 3) {
			post4L[avgPos%4] = darkSampleL;
			darkSampleL = 0.0;
			for (int x = 0; x < 4; x++) {darkSampleL += post4L[x];}
			darkSampleL /= 4.0;
		} if (slewsing > 1) {
			post2L[avgPos%2] = darkSampleL;
			darkSampleL = 0.0;
			for (int x = 0; x < 2; x++) {darkSampleL += post2L[x];}
			darkSampleL /= 2.0; 
		} avgPos++;
		inputSampleL = (inputSampleL*(1.0-avgSlewL)) + (darkSampleL*avgSlewL);
		//use the previously calculated depth of the filter
		
		//begin HeadBump
		double headBumpSampleL = 0.0;
		if (headBumpMix > 0.0) {
			headBumpL += (inputSampleL * headBumpDrive);
			headBumpL -= (headBumpL * headBumpL * headBumpL * (0.0618/sqrt(overallscale)));
			double headBiqSampleL = (headBumpL * hdbA[hdb_a0]) + hdbA[hdb_sL1];
			hdbA[hdb_sL1] = (headBumpL * hdbA[hdb_a1]) - (headBiqSampleL * hdbA[hdb_b1]) + hdbA[hdb_sL2];
			hdbA[hdb_sL2] = (headBumpL * hdbA[hdb_a2]) - (headBiqSampleL * hdbA[hdb_b2]);
			headBumpSampleL = (headBiqSampleL * hdbB[hdb_a0]) + hdbB[hdb_sL1];
			hdbB[hdb_sL1] = (headBiqSampleL * hdbB[hdb_a1]) - (headBumpSampleL * hdbB[hdb_b1]) + hdbB[hdb_sL2];
			hdbB[hdb_sL2] = (headBiqSampleL * hdbB[hdb_a2]) - (headBumpSampleL * hdbB[hdb_b2]);
		}
		//end HeadBump
		
		inputSampleL += (headBumpSampleL * headBumpMix);
		
		//Dubly decode
		iirDecL = (iirDecL * (1.0 - iirDecFreq)) + (inputSampleL * iirDecFreq);
		highPart = ((inputSampleL-iirDecL)*2.628);
		highPart += avgDecL; avgDecL = (inputSampleL-iirDecL)*1.372;
		if (highPart > 1.0) highPart = 1.0; if (highPart < -1.0) highPart = -1.0;
		dubly = fabs(highPart);
		if (dubly > 0.0) {
			double adjust = log(1.0+(255.0*dubly))/2.40823996531;
			if (adjust > 0.0) dubly /= adjust;
			compDecL = (compDecL*(1.0-iirDecFreq))+(dubly*iirDecFreq);
			inputSampleL += ((highPart*compDecL)*outlyAmount);
		} //end Dubly decode L
		
		if (outputGain != 1.0) {
			inputSampleL *= outputGain;
		}
		
		//begin ClipOnly3 as a little, compressed chunk that can be dropped into code
		double noise = 1.0-((double(fpdL)/UINT32_MAX)*0.076);
		if (wasPosClipL == true) { //current will be over
			if (inputSampleL<lastSampleL) lastSampleL=(0.9085097*noise)+(inputSampleL*(1.0-noise));
			else lastSampleL = 0.94; //~-0.2dB to nearly match ClipOnly and ClipOnly2
		} wasPosClipL = false;
		if (inputSampleL>0.9085097) {wasPosClipL=true;inputSampleL=(0.9085097*noise)+(lastSampleL*(1.0-noise));}
		if (wasNegClipL == true) { //current will be -over
			if (inputSampleL > lastSampleL) lastSampleL=(-0.9085097*noise)+(inputSampleL*(1.0-noise));
			else lastSampleL = -0.94;
		} wasNegClipL = false;
		if (inputSampleL<-0.9085097) {wasNegClipL=true;inputSampleL=(-0.9085097*noise)+(lastSampleL*(1.0-noise));}
		slewL[spacing*2] = fabs(lastSampleL-inputSampleL);
		for (int x = spacing*2; x > 0; x--) slewL[x-1] = slewL[x];
		intermediateL[spacing] = inputSampleL; inputSampleL = lastSampleL;
		//Latency is however many samples equals one 44.1k sample
		for (int x = spacing; x > 0; x--) {intermediateL[x-1] = intermediateL[x];} lastSampleL = intermediateL[0];
		if (wasPosClipL || wasNegClipL) {
			for (int x = spacing; x > 0; x--) lastSampleL += intermediateL[x];
			lastSampleL /= spacing;
		} double finalSlew = 0.0;
		for (int x = spacing*2; x >= 0; x--) if (finalSlew < slewL[x]) finalSlew = slewL[x];
		double postclip = 0.94 / (1.0+(finalSlew*1.3986013));
		if (inputSampleL > postclip) inputSampleL = postclip; if (inputSampleL < -postclip) inputSampleL = -postclip;
		//end ClipOnly3 as a little, compressed chunk that can be dropped into code
		
		
		//begin 32 bit floating point dither
		int expon; frexpf((float)inputSampleL, &expon);
		fpdL ^= fpdL << 13; fpdL ^= fpdL >> 17; fpdL ^= fpdL << 5;
		inputSampleL += ((double(fpdL)-uint32_t(0x7fffffff)) * 5.5e-36l * pow(2,expon+62));
		//end 32 bit floating point dither
		
		*destP = inputSampleL;
		
		sourceP += inNumChannels; destP += inNumChannels;
	}
}

