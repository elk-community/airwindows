/*
*	File:		ConsoleX3Mono.cpp
*	
*	Version:	1.0
* 
*	Created:	7/9/26
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
	ConsoleX3Mono.cpp
	
=============================================================================*/
#include "ConsoleX3Mono.h"


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

AUDIOCOMPONENT_ENTRY(AUBaseFactory, ConsoleX3Mono)


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	ConsoleX3Mono::ConsoleX3Mono
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ConsoleX3Mono::ConsoleX3Mono(AudioUnit component)
	: AUEffectBase(component)
{
	CreateElements();
	Globals()->UseIndexedParameters(kNumberOfParameters);
	
	SetParameter(kParam_HIG, kDefaultValue_ParamHIG );
	SetParameter(kParam_HMG, kDefaultValue_ParamHMG );
	SetParameter(kParam_LMG, kDefaultValue_ParamLMG );
	SetParameter(kParam_BSG, kDefaultValue_ParamBSG );
	SetParameter(kParam_HIF, kDefaultValue_ParamHIF );
	SetParameter(kParam_HMF, kDefaultValue_ParamHMF );
	SetParameter(kParam_LMF, kDefaultValue_ParamLMF );
	SetParameter(kParam_BSF, kDefaultValue_ParamBSF );
	
	SetParameter(kParam_THR, kDefaultValue_ParamTHR );
	SetParameter(kParam_ATK, kDefaultValue_ParamATK );
	SetParameter(kParam_RLS, kDefaultValue_ParamRLS );
	SetParameter(kParam_RAT, kDefaultValue_ParamRAT );
	
	SetParameter(kParam_TRM, kDefaultValue_ParamTRM );
	SetParameter(kParam_MDE, kDefaultValue_ParamMDE );
	SetParameter(kParam_SMO, kDefaultValue_ParamSMO );
	SetParameter(kParam_MOR, kDefaultValue_ParamMOR );
	
	SetParameter(kParam_LOP, kDefaultValue_ParamLOP );
	SetParameter(kParam_LPQ, kDefaultValue_ParamLPQ );
	SetParameter(kParam_HIP, kDefaultValue_ParamHIP );
	SetParameter(kParam_HPQ, kDefaultValue_ParamHPQ );
	
	SetParameter(kParam_FAD, kDefaultValue_ParamFAD );
		
#if AU_DEBUG_DISPATCHER
	mDebugDispatcher = new AUDebugDispatcher (this);
#endif
	
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	ConsoleX3Mono::GetParameterValueStrings
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult			ConsoleX3Mono::GetParameterValueStrings(AudioUnitScope		inScope,
                                                                AudioUnitParameterID	inParameterID,
                                                                CFArrayRef *		outStrings)
{
        
    return kAudioUnitErr_InvalidProperty;
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	ConsoleX3Mono::GetParameterInfo
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult			ConsoleX3Mono::GetParameterInfo(AudioUnitScope		inScope,
                                                        AudioUnitParameterID	inParameterID,
                                                        AudioUnitParameterInfo	&outParameterInfo )
{
	ComponentResult result = noErr;

	outParameterInfo.flags = 	kAudioUnitParameterFlag_IsWritable
						|		kAudioUnitParameterFlag_IsReadable;
    
    if (inScope == kAudioUnitScope_Global) {
        switch(inParameterID)
        {
            case kParam_HIG:
                AUBase::FillInParameterName (outParameterInfo, kParameterHIGName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_CustomUnit;
				outParameterInfo.unitName = kParameterHIGUnit;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamHIG;
                break;
            case kParam_HMG:
                AUBase::FillInParameterName (outParameterInfo, kParameterHMGName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamHMG;
                break;
            case kParam_LMG:
                AUBase::FillInParameterName (outParameterInfo, kParameterLMGName, false);
 				outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamLMG;
                break;
            case kParam_BSG:
                AUBase::FillInParameterName (outParameterInfo, kParameterBSGName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamBSG;
                break;
            case kParam_HIF:
                AUBase::FillInParameterName (outParameterInfo, kParameterHIFName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_CustomUnit;
				outParameterInfo.unitName = kParameterHIFUnit;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamHIF;
                break;
            case kParam_HMF:
                AUBase::FillInParameterName (outParameterInfo, kParameterHMFName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamHMF;
                break;
            case kParam_LMF:
                AUBase::FillInParameterName (outParameterInfo, kParameterLMFName, false);
 				outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamLMF;
                break;
            case kParam_BSF:
                AUBase::FillInParameterName (outParameterInfo, kParameterBSFName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamBSF;
                break;
            case kParam_THR:
                AUBase::FillInParameterName (outParameterInfo, kParameterTHRName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_CustomUnit;
				outParameterInfo.unitName = kParameterTHRUnit;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamTHR;
                break;
            case kParam_ATK:
                AUBase::FillInParameterName (outParameterInfo, kParameterATKName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamATK;
                break;
            case kParam_RLS:
                AUBase::FillInParameterName (outParameterInfo, kParameterRLSName, false);
 				outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
				outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamRLS;
                break;
            case kParam_RAT:
                AUBase::FillInParameterName (outParameterInfo, kParameterRATName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamRAT;
                break;
            case kParam_TRM:
                AUBase::FillInParameterName (outParameterInfo, kParameterTRMName, false);
 				outParameterInfo.unit = kAudioUnitParameterUnit_CustomUnit;
				outParameterInfo.unitName = kParameterTRMUnit;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamTRM;
                break;
			case kParam_MDE:
                AUBase::FillInParameterName (outParameterInfo, kParameterMDEName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_CustomUnit;
 				outParameterInfo.unitName = kParameterMDEUnit;
				outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamMDE;
                break;
			case kParam_SMO:
                AUBase::FillInParameterName (outParameterInfo, kParameterSMOName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamSMO;
                break;
            case kParam_MOR:
                AUBase::FillInParameterName (outParameterInfo, kParameterMORName, false);
  				outParameterInfo.unit = kAudioUnitParameterUnit_CustomUnit;
				outParameterInfo.unitName = kParameterMORUnit;
				outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamMOR;
                break;
            case kParam_LOP:
                AUBase::FillInParameterName (outParameterInfo, kParameterLOPName, false);
				outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamLOP;
                break;
            case kParam_LPQ:
                AUBase::FillInParameterName (outParameterInfo, kParameterLPQName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
				outParameterInfo.defaultValue = kDefaultValue_ParamLPQ;
                break;
            case kParam_HIP:
                AUBase::FillInParameterName (outParameterInfo, kParameterHIPName, false);
                outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamHIP;
                break;
            case kParam_HPQ:
                AUBase::FillInParameterName (outParameterInfo, kParameterHPQName, false);
				outParameterInfo.unit = kAudioUnitParameterUnit_Generic;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamHPQ;
                break;
            case kParam_FAD:
                AUBase::FillInParameterName (outParameterInfo, kParameterFADName, false);
 				outParameterInfo.unit = kAudioUnitParameterUnit_CustomUnit;
				outParameterInfo.unitName = kParameterFADUnit;
                outParameterInfo.minValue = 0.0;
                outParameterInfo.maxValue = 1.0;
                outParameterInfo.defaultValue = kDefaultValue_ParamFAD;
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
//	ConsoleX3Mono::GetPropertyInfo
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult			ConsoleX3Mono::GetPropertyInfo (AudioUnitPropertyID	inID,
                                                        AudioUnitScope		inScope,
                                                        AudioUnitElement	inElement,
                                                        UInt32 &		outDataSize,
                                                        Boolean &		outWritable)
{
	return AUEffectBase::GetPropertyInfo (inID, inScope, inElement, outDataSize, outWritable);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	ConsoleX3Mono::GetProperty
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult			ConsoleX3Mono::GetProperty(	AudioUnitPropertyID inID,
                                                        AudioUnitScope 		inScope,
                                                        AudioUnitElement 	inElement,
                                                        void *			outData )
{
	return AUEffectBase::GetProperty (inID, inScope, inElement, outData);
}

//	ConsoleX3Mono::Initialize
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ComponentResult ConsoleX3Mono::Initialize()
{
    ComponentResult result = AUEffectBase::Initialize();
    if (result == noErr)
        Reset(kAudioUnitScope_Global, 0);
    return result;
}

#pragma mark ____ConsoleX3MonoEffectKernel



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	ConsoleX3Mono::ConsoleX3MonoKernel::Reset()
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void		ConsoleX3Mono::ConsoleX3MonoKernel::Reset()
{
	for (int x = 0; x < bezier_total; x++) bezier[x] = 0.0;
	//Control Smoothing
	
	for (int x = 0; x < bez_EQtotal; x++) {for (int y = 0; y < 3; y++) bezEQ[x][y] = 0.0;}
	//BezEQ4
	
	for (int x = 0; x < bez_total; x++) bezComp[x] = 0.0;
	//Dynamics3
	
	for(int count = 0; count < 28; count++) {
		iirHPositionL[count] = 0.0;
		iirHAngleL[count] = 0.0;
	}
	hBypass = false;
	for(int count = 0; count < 28; count++) {
		iirLPositionL[count] = 0.0;
		iirLAngleL[count] = 0.0;
	}
	lBypass = false;	
	//Cabs2
	
	for (int x = 0; x < bip_total; x++) bip[x] = 0.0;
	
	fpd = 1.0; while (fpd < 16386) fpd = rand()*UINT32_MAX;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	ConsoleX3Mono::ConsoleX3MonoKernel::Process
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void		ConsoleX3Mono::ConsoleX3MonoKernel::Process(	const Float32 	*inSourceP,
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
	
	double bezierRez = fmax(pow((1.0-GetParameter( kParam_SMO ))*0.25,3.0)/overallscale,0.00001); 
	int stepped = 999999; if (bezierRez > 0.000001) stepped = (int)(1.0/bezierRez); bezierRez = 0.99999999/stepped;
	const double bezierTrim = 1.0-(bezierRez*((double)stepped/(stepped+1.0)));
	//manages the overall Bezier control smoothing system plugin-wide	
	int spacing = floor(overallscale*2.0);
	if (spacing < 2) spacing = 2; if (spacing > 32) spacing = 32;
	const double gainTrim = GetParameter( kParam_TRM )*2.0;
	const double trebleRef = GetParameter( kParam_HIF )-0.3;
	const double highmidRef = GetParameter( kParam_HMF )-0.5;
	const double lowmidRef = GetParameter( kParam_LMF )-0.7;
	const double bassRef = GetParameter( kParam_BSF )-0.9;
	double HMderez = 0.75 + (trebleRef*0.25);
	double LMderez = 0.25 + (bassRef*0.25);
	double Mderez = ((HMderez+LMderez+highmidRef+lowmidRef)*0.25);
	HMderez /= overallscale; Mderez /= overallscale; LMderez /= overallscale;
	if (HMderez > 1.0) HMderez = 1.0;
	stepped = 999999; if (HMderez > 0.000001) stepped = (int)(1.0/HMderez);
	HMderez = 0.99999999 / stepped;
	double HMtrim = 1.0-(HMderez*((double)stepped/(stepped+1.0)));
	stepped = 999999; if (Mderez > 0.000001) stepped = (int)(1.0/Mderez);
	Mderez = 0.99999999 / stepped;
	double Mtrim = 1.0-(Mderez*((double)stepped/(stepped+1.0)));
	stepped = 999999; if (LMderez > 0.000001) stepped = (int)(1.0/LMderez);
	LMderez = 0.99999999 / stepped;
	const double LMtrim = 1.0-(LMderez*((double)stepped/(stepped+1.0)));
	//BezEQ3 stepped elements
	double bezRez = fmax(pow((1.0-GetParameter( kParam_ATK ))*0.4,4.0)/overallscale,0.0001); 
	bezRez /= (2.0/pow(overallscale,0.5-((overallscale-1.0)*0.0375)));
	stepped = 999999; if (bezRez > 0.000001) stepped = (int)(1.0/bezRez);
	bezRez = 0.99999999 / stepped;
	double bezTrim = 1.0-(bezRez*((double)stepped/(stepped+1.0)));
	double sloRez = fmax(pow((1.0-GetParameter( kParam_RLS ))*0.4,4.0)/overallscale,0.00001);
	sloRez /= (2.0/pow(overallscale,0.5-((overallscale-1.0)*0.0375)));
	double sqrThresh = 1.0; //recalculated in bezier section
	double bezThresh = bezier[bezierThresh];
	double invDry = bezier[bezierRatio];
	bool compress = (GetParameter( kParam_RAT ) > 0.499999);
	bool compBypass = (GetParameter( kParam_THR ) > 0.9999);
	bool tapeBypass = (GetParameter( kParam_MOR ) < 0.0001);
	double pluginMode = GetParameter( kParam_MDE );
	//Dynamics3 stepped elements
	const int Lpoles = pow(GetParameter( kParam_LPQ )*3.0,3.0)+1;
	const int Hpoles = pow(GetParameter( kParam_HPQ )*3.0,3.0)+1; //1-28 pole filter
	//Lowpass/Highpass stepped elements
	
	while (nSampleFrames-- > 0) {
		double inputSampleL = *sourceP;
		if (fabs(inputSampleL)<1.18e-23) inputSampleL = fpd * 1.18e-17;
		
		if (pluginMode > 0.5) {
            double dryL = inputSampleL;
            if (inputSampleL > 1.0) inputSampleL = 1.0;
            else if (inputSampleL > 0.0) inputSampleL = -expm1((log1p(-inputSampleL) * 0.6180339887498949));
            if (inputSampleL < -1.0) inputSampleL = -1.0;
            else if (inputSampleL < 0.0) inputSampleL = expm1((log1p(inputSampleL) * 0.6180339887498949));
			bip[bip_dvA] = dryL - inputSampleL; // these are derivatives: raw clip is position
			bip[bip_dvB] = bip[bip_pvA]-bip[bip_dvA]; bip[bip_pvA] = bip[bip_dvA];//velocity
			bip[bip_dvC] = bip[bip_pvB]-bip[bip_dvB]; bip[bip_pvB] = bip[bip_dvB];//acceleration
			bip[bip_dvD] = bip[bip_pvC]-bip[bip_dvC]; bip[bip_pvC] = bip[bip_dvC];//jerk
			double bip_dvE = bip[bip_pvD]-bip[bip_dvD]; bip[bip_pvD] = bip[bip_dvD];//snap
			inputSampleL *= (1.0+(fabs(bip[bip_dvC])*0.0618)+(fabs(bip[bip_dvD])*-0.05982)+(fabs(bip_dvE)*0.0206));
            if (pluginMode < 1.0f) {
                inputSampleL = (dryL*(1.0-((pluginMode-0.5)*2.0))) + (inputSampleL*((pluginMode-0.5)*2.0));
            }
        } //engage pluginMode, buss		
		
		//begin Bezier control smoothing engine
		bezier[bezier_cycle] += bezierRez;
		if (bezier[bezier_cycle] > bezierTrim) {bezier[bezier_cycle] = 0.0;
			bezier[bezierHigh_C] =  bezier[bezierHigh_B];  bezier[bezierHigh_B] =  bezier[bezierHigh_A];
			bezier[bezierHmid_C] =  bezier[bezierHmid_B];  bezier[bezierHmid_B] =  bezier[bezierHmid_A];
			bezier[bezierLmid_C] =  bezier[bezierLmid_B];  bezier[bezierLmid_B] =  bezier[bezierLmid_A];
			bezier[bezierBass_C] =  bezier[bezierBass_B];  bezier[bezierBass_B] =  bezier[bezierBass_A];
			bezier[bezierHighQ_C] = bezier[bezierHighQ_B]; bezier[bezierHighQ_B] = bezier[bezierHighQ_A];
			bezier[bezierMidQ_C] =  bezier[bezierMidQ_B];  bezier[bezierMidQ_B] =  bezier[bezierMidQ_A];
			bezier[bezierLowQ_C] =  bezier[bezierLowQ_B];  bezier[bezierLowQ_B] =  bezier[bezierLowQ_A];
			bezier[bezierThresh_C]= bezier[bezierThresh_B];bezier[bezierThresh_B]= bezier[bezierThresh_A];
			bezier[bezierRatio_C] = bezier[bezierRatio_B]; bezier[bezierRatio_B] = bezier[bezierRatio_A];
			bezier[bezierMore_C] =  bezier[bezierMore_B];  bezier[bezierMore_B] =  bezier[bezierMore_A];
			bezier[bezierLFreq_C] = bezier[bezierLFreq_B]; bezier[bezierLFreq_B] = bezier[bezierLFreq_A];
			bezier[bezierHFreq_C] = bezier[bezierHFreq_B]; bezier[bezierHFreq_B] = bezier[bezierHFreq_A];
			bezier[bezierGainL_C] = bezier[bezierGainL_B]; bezier[bezierGainL_B] = bezier[bezierGainL_A];
			//one of these bucket brigade lines for every smoothed control
			//begin smoothed control calculations			
			bezier[bezierHigh_A] = (pow(GetParameter( kParam_HIG )+0.5,3.0)+2.0)*0.3333333;
			bezier[bezierHmid_A] = (pow(GetParameter( kParam_HMG )+0.5,3.0)+2.0)*0.3333333;
			bezier[bezierLmid_A] = (pow(GetParameter( kParam_LMG )+0.5,3.0)+2.0)*0.3333333;
			bezier[bezierBass_A] = (pow(GetParameter( kParam_BSG )+0.5,3.0)+2.0)*0.3333333;
			bezier[bezierHighQ_A] = 0.84+((highmidRef-trebleRef)*0.1666666);
			bezier[bezierMidQ_A] = 0.84+((lowmidRef-highmidRef)*0.1666666);
			bezier[bezierLowQ_A] = 0.84+((bassRef-lowmidRef)*0.1666666);
			//BezEQ3
			bezier[bezierThresh_A] = pow(GetParameter( kParam_THR )+0.6180339887498949,2.0)*1.6180339887498949;
			sqrThresh = sqrt(bezier[bezierThresh_A]);
			bezier[bezierRatio_A] = pow(1.0-(fabs(GetParameter( kParam_RAT )-0.5)*2.0),1.6180339887498949);
			//Dynamics3
			bezier[bezierMore_A] = (GetParameter( kParam_MOR )*3.0)+1.0;
			//TapeHack
			bezier[bezierLFreq_A] = pow(fmax(GetParameter( kParam_LOP ),0.002),overallscale); //the lowpass
			bezier[bezierHFreq_A] = pow(GetParameter( kParam_HIP ),overallscale+2.0); //the highpass
			//Cabs2
			bezier[bezierGainL_A] = pow(GetParameter( kParam_FAD ),2.0);
			//Fader
			//end expensive control calculations
		} 
		const double lerp = bezier[bezier_cycle]; //with this many controls we'll make temp variables
		const double La = (1.0-lerp)*(1.0-lerp); const double Lb = 2.0*(1.0-lerp)*lerp; const double Lc = lerp*lerp;
		bezier[bezierHigh] = (bezier[bezierHigh_B] + (bezier[bezierHigh_C]*La) + (bezier[bezierHigh_B]*Lb) + (bezier[bezierHigh_A]*Lc))*0.5;
		bezier[bezierHmid] = (bezier[bezierHmid_B] + (bezier[bezierHmid_C]*La) + (bezier[bezierHmid_B]*Lb) + (bezier[bezierHmid_A]*Lc))*0.5;
		bezier[bezierLmid] = (bezier[bezierLmid_B] + (bezier[bezierLmid_C]*La) + (bezier[bezierLmid_B]*Lb) + (bezier[bezierLmid_A]*Lc))*0.5;
		bezier[bezierBass] = (bezier[bezierBass_B] + (bezier[bezierBass_C]*La) + (bezier[bezierBass_B]*Lb) + (bezier[bezierBass_A]*Lc))*0.5;
		bezier[bezierHighQ] = (bezier[bezierHighQ_B] + (bezier[bezierHighQ_C]*La) + (bezier[bezierHighQ_B]*Lb) + (bezier[bezierHighQ_A]*Lc))*0.5;
		bezier[bezierMidQ] = (bezier[bezierMidQ_B] + (bezier[bezierMidQ_C]*La) + (bezier[bezierMidQ_B]*Lb) + (bezier[bezierMidQ_A]*Lc))*0.5;
		bezier[bezierLowQ] = (bezier[bezierLowQ_B] + (bezier[bezierLowQ_C]*La) + (bezier[bezierLowQ_B]*Lb) + (bezier[bezierLowQ_A]*Lc))*0.5;
		bezier[bezierThresh] = (bezier[bezierThresh_B] + (bezier[bezierThresh_C]*La) + (bezier[bezierThresh_B]*Lb) + (bezier[bezierThresh_A]*Lc))*0.5;
		bezier[bezierRatio] = (bezier[bezierRatio_B] + (bezier[bezierRatio_C]*La) + (bezier[bezierRatio_B]*Lb) + (bezier[bezierRatio_A]*Lc))*0.5;
		bezier[bezierMore] = (bezier[bezierMore_B] + (bezier[bezierMore_C]*La) + (bezier[bezierMore_B]*Lb) + (bezier[bezierMore_A]*Lc))*0.5;
		bezier[bezierLFreq] = (bezier[bezierLFreq_B] + (bezier[bezierLFreq_C]*La) + (bezier[bezierLFreq_B]*Lb) + (bezier[bezierLFreq_A]*Lc))*0.5;
		bezier[bezierHFreq] = (bezier[bezierHFreq_B] + (bezier[bezierHFreq_C]*La) + (bezier[bezierHFreq_B]*Lb) + (bezier[bezierHFreq_A]*Lc))*0.5;
		bezier[bezierGainL] = (bezier[bezierGainL_B] + (bezier[bezierGainL_C]*La) + (bezier[bezierGainL_B]*Lb) + (bezier[bezierGainL_A]*Lc))*0.5;
		//end Bezier control smoothing engine
		
		//begin Trim switch
		if (gainTrim != 1.0) {inputSampleL *= gainTrim;}
		//end Trim switch
		
		//begin BezEQ4 Pre
		double highL = inputSampleL;
		bezEQ[bez_HMcycle][0] += HMderez;
		bezEQ[bez_HMAL][0] += (highL * HMderez);
		if (bezEQ[bez_HMcycle][0] > HMtrim) {
			bezEQ[bez_HMDL][0] = bezEQ[bez_HMCL][0]; bezEQ[bez_HMCL][0] = bezEQ[bez_HMBL][0]; 
			bezEQ[bez_HMBL][0] = bezEQ[bez_HMAL][0]*(0.5-(HMderez*0.082));
			bezEQ[bez_HMAL][0] = 0.0; bezEQ[bez_HMcycle][0] = 0.0;
		}
		double X = bezEQ[bez_HMcycle][0];
		double hmidL = bezEQ[bez_HMCL][0]+(bezEQ[bez_HMDL][0]*(1.0-X)*(1.0-X));
		hmidL += (bezEQ[bez_HMCL][0]*2.0*(1.0-X)*X)+(bezEQ[bez_HMBL][0]*X*X);
		hmidL *= bezier[bezierHighQ];
		highL -= hmidL; //final high and hmid
		bezEQ[bez_Mcycle][0] += Mderez;
		bezEQ[bez_MAL][0] += (hmidL * Mderez);
		if (bezEQ[bez_Mcycle][0] > Mtrim) {
			bezEQ[bez_MDL][0] = bezEQ[bez_MCL][0]; bezEQ[bez_MCL][0] = bezEQ[bez_MBL][0]; 
			bezEQ[bez_MBL][0] = bezEQ[bez_MAL][0]*(0.5-(Mderez*0.082));
			bezEQ[bez_MAL][0] = 0.0; bezEQ[bez_Mcycle][0] = 0.0;
		}
		X = bezEQ[bez_Mcycle][0];
		double lmidL = bezEQ[bez_MCL][0]+(bezEQ[bez_MDL][0]*(1.0-X)*(1.0-X));
		lmidL += (bezEQ[bez_MCL][0]*2.0*(1.0-X)*X)+(bezEQ[bez_MBL][0]*X*X);
		lmidL *= bezier[bezierMidQ];
		hmidL -= lmidL; //final hmid and lmid
		bezEQ[bez_LMcycle][0] += LMderez;
		bezEQ[bez_LMAL][0] += (lmidL * LMderez);
		if (bezEQ[bez_LMcycle][0] > LMtrim) {
			bezEQ[bez_LMDL][0] = bezEQ[bez_LMCL][0]; bezEQ[bez_LMCL][0] = bezEQ[bez_LMBL][0]; 
			bezEQ[bez_LMBL][0] = bezEQ[bez_LMAL][0]*(0.5-(LMderez*0.082));
			bezEQ[bez_LMAL][0] = 0.0; bezEQ[bez_LMcycle][0] = 0.0;
		}
		X = bezEQ[bez_LMcycle][0];
		double bassL = bezEQ[bez_LMCL][0]+(bezEQ[bez_LMDL][0]*(1.0-X)*(1.0-X));
		bassL += (bezEQ[bez_LMCL][0]*2.0*(1.0-X)*X)+(bezEQ[bez_LMBL][0]*X*X);
		bassL *= bezier[bezierLowQ];
		lmidL -= bassL; //final lmid and bass
		inputSampleL = (highL*bezier[bezierHigh])+(hmidL*bezier[bezierHmid])+(lmidL*bezier[bezierLmid])+(bassL*bezier[bezierBass]);
		//end BezEQ4 Pre
		
		if (!compBypass) {
			//begin Dynamics3
			double dryCompL = inputSampleL;
			if (compress) inputSampleL *= (bezComp[bez_comp]/bezThresh);
			else inputSampleL /= bezThresh;
			double ctrl = fmin(inputSampleL,sqrThresh*bezComp[bez_comp]*0.6180339887498949);
			bezComp[bez_min] = fmax(bezComp[bez_min]-sloRez,ctrl);
			bezComp[bez_Ctrl] += (bezComp[bez_min] * bezRez);
			bezComp[bez_cycle] += bezRez;
			if (bezComp[bez_cycle] > bezTrim) {bezComp[bez_cycle] = 0.0;
				bezComp[bez_C] = bezComp[bez_B]; bezComp[bez_B] = bezComp[bez_A];
				bezComp[bez_A] = bezComp[bez_Ctrl]; bezComp[bez_Ctrl] = 0.0;}
			double X = bezComp[bez_cycle];
			bezComp[bez_comp] = bezComp[bez_B]+(bezComp[bez_C]*(1.0-X)*(1.0-X))+(bezComp[bez_B]*2.0*(1.0-X)*X)+(bezComp[bez_A]*X*X);
			bezComp[bez_comp] = ((1.0-(fmin(bezComp[bez_comp],0.9999))));
			if (compress) {
				inputSampleL = inputSampleL*(1.0-invDry)*bezComp[bez_comp]*bezThresh;
				inputSampleL = fmax(fmin(inputSampleL,2.305929007734908),-2.305929007734908);
				double addtwo = inputSampleL * inputSampleL;
				double empower = inputSampleL * addtwo; // inputSampleL to the third power
				inputSampleL -= (empower / 6.0); empower *= addtwo; // to the fifth power
				inputSampleL += (empower / 69.0); empower *= addtwo; //seventh
				inputSampleL -= (empower / 2530.08); empower *= addtwo; //ninth
				inputSampleL += (empower / 224985.6); empower *= addtwo; //eleventh
				inputSampleL -= (empower / 9979200.0f);
				//this is a degenerate form of a Taylor Series to approximate sin()				
				inputSampleL += (dryCompL*invDry*(1.0-(bezComp[bez_comp]*(1.0-invDry))));
			} else {
				inputSampleL = ((inputSampleL/(0.1+bezThresh))*(1.0-invDry))/bezComp[bez_comp];
				inputSampleL = fmax(fmin(inputSampleL,2.305929007734908),-2.305929007734908);
				double addtwo = inputSampleL * inputSampleL;
				double empower = inputSampleL * addtwo; // inputSampleL to the third power
				inputSampleL -= (empower / 6.0); empower *= addtwo; // to the fifth power
				inputSampleL += (empower / 69.0); empower *= addtwo; //seventh
				inputSampleL -= (empower / 2530.08); empower *= addtwo; //ninth
				inputSampleL += (empower / 224985.6); empower *= addtwo; //eleventh
				inputSampleL -= (empower / 9979200.0f);
				//this is a degenerate form of a Taylor Series to approximate sin()				
				inputSampleL += (dryCompL*invDry*(1.0-(bezComp[bez_comp]*(1.0-invDry))));
			}//dynamics can produce superhot peaks
			//end Dynamics3
		}
		
		//begin BezEQ4 Mid
		highL = inputSampleL;
		bezEQ[bez_HMcycle][1] += HMderez;
		bezEQ[bez_HMAL][1] += (highL * HMderez);
		if (bezEQ[bez_HMcycle][1] > HMtrim) {
			bezEQ[bez_HMDL][1] = bezEQ[bez_HMCL][1]; bezEQ[bez_HMCL][1] = bezEQ[bez_HMBL][1]; 
			bezEQ[bez_HMBL][1] = bezEQ[bez_HMAL][1]*(0.5-(HMderez*0.082));
			bezEQ[bez_HMAL][1] = 0.0; bezEQ[bez_HMcycle][1] = 0.0;
		}
		X = bezEQ[bez_HMcycle][1];
		hmidL = bezEQ[bez_HMCL][1]+(bezEQ[bez_HMDL][1]*(1.0-X)*(1.0-X));
		hmidL += (bezEQ[bez_HMCL][1]*2.0*(1.0-X)*X)+(bezEQ[bez_HMBL][1]*X*X);
		hmidL *= bezier[bezierHighQ];
		highL -= hmidL; //final high and hmid
		bezEQ[bez_Mcycle][1] += Mderez;
		bezEQ[bez_MAL][1] += (hmidL * Mderez);
		if (bezEQ[bez_Mcycle][1] > Mtrim) {
			bezEQ[bez_MDL][1] = bezEQ[bez_MCL][1]; bezEQ[bez_MCL][1] = bezEQ[bez_MBL][1]; 
			bezEQ[bez_MBL][1] = bezEQ[bez_MAL][1]*(0.5-(Mderez*0.082));
			bezEQ[bez_MAL][1] = 0.0; bezEQ[bez_Mcycle][1] = 0.0;
		}
		X = bezEQ[bez_Mcycle][1];
		lmidL = bezEQ[bez_MCL][1]+(bezEQ[bez_MDL][1]*(1.0-X)*(1.0-X));
		lmidL += (bezEQ[bez_MCL][1]*2.0*(1.0-X)*X)+(bezEQ[bez_MBL][1]*X*X);
		lmidL *= bezier[bezierMidQ];
		hmidL -= lmidL; //final hmid and lmid
		bezEQ[bez_LMcycle][1] += LMderez;
		bezEQ[bez_LMAL][1] += (lmidL * LMderez);
		if (bezEQ[bez_LMcycle][1] > LMtrim) {
			bezEQ[bez_LMDL][1] = bezEQ[bez_LMCL][1]; bezEQ[bez_LMCL][1] = bezEQ[bez_LMBL][1]; 
			bezEQ[bez_LMBL][1] = bezEQ[bez_LMAL][1]*(0.5-(LMderez*0.082));
			bezEQ[bez_LMAL][1] = 0.0; bezEQ[bez_LMcycle][1] = 0.0;
		}
		X = bezEQ[bez_LMcycle][1];
		bassL = bezEQ[bez_LMCL][1]+(bezEQ[bez_LMDL][1]*(1.0-X)*(1.0-X));
		bassL += (bezEQ[bez_LMCL][1]*2.0*(1.0-X)*X)+(bezEQ[bez_LMBL][1]*X*X);
		bassL *= bezier[bezierLowQ];
		lmidL -= bassL; //final lmid and bass
		inputSampleL = (highL*bezier[bezierHigh])+(hmidL*bezier[bezierHmid])+(lmidL*bezier[bezierLmid])+(bassL*bezier[bezierBass]);
		//end BezEQ4 Mid
		
		//begin Weave
		if (!tapeBypass) {
			inputSampleL *= bezier[bezierMore];
			double bip_delta = inputSampleL; //delta can be just local and re-used
			if (inputSampleL != 0.0) {
				inputSampleL = fmax(fmin(inputSampleL,1.0),-1.0);
				inputSampleL *= 1.27;
				double weave = sqrt(fabs(inputSampleL));
				double spiral = inputSampleL * weave;
				long double X = spiral; X *= X;
				long double temp = spiral * X;
				spiral -= temp*0.16666666666666666666666666666666666; temp *= X;//-8 dB
				spiral += temp*0.00833333333333333333333333333333333; temp *= X;//-20 dB
				spiral -= temp*0.00019841269841269841269841269841269; temp *= X;//-37 dB
				spiral += temp*0.00000275573192239858906525573192239; temp *= X;//-55 dB
				spiral -= temp*0.00000002505210838544171877521083854; temp *= X;//-76 dB
				spiral += temp*0.00000000016059043836821614599392377; temp *= X;//-108 dB
				spiral -= temp*0.00000000000076471637318198164759011; temp *= X;//-121 dB
				spiral += temp*0.00000000000000281145725434552076319; temp *= X;//-146 dB
				spiral -= temp*0.00000000000000000822063524662432971; temp *= X;//-171 dB
				spiral += temp*0.00000000000000000001957294106339126;           //-197 dB
				inputSampleL = spiral / weave; //purest form is full Spiral
			} //version of Weave in ConsoleX uses A and B for derivatives, not L and R
			bip[bip_dvAA] = bip_delta - inputSampleL; // these are derivatives: raw clip is position
			bip[bip_dvAB] = bip[bip_pvAA]-bip[bip_dvAA]; bip[bip_pvAA] = bip[bip_dvAA];//velocity
			bip[bip_dvAC] = bip[bip_pvAB]-bip[bip_dvAB]; bip[bip_pvAB] = bip[bip_dvAB];//acceleration
			bip[bip_dvAD] = bip[bip_pvAC]-bip[bip_dvAC]; bip[bip_pvAC] = bip[bip_dvAC];//jerk
			double bip_dvE = bip[bip_pvAD]-bip[bip_dvAD]; bip[bip_pvAD] = bip[bip_dvAD];//snap
			inputSampleL *= (1.0+(fabs(bip[bip_dvAC])*0.0618)+(fabs(bip[bip_dvAD])*-0.05982)+(fabs(bip_dvE)*0.0206));
		} //end Weave
		
		//begin BezEQ4 Post 
		highL = inputSampleL;
		bezEQ[bez_HMcycle][2] += HMderez;
		bezEQ[bez_HMAL][2] += (highL * HMderez);
		if (bezEQ[bez_HMcycle][2] > HMtrim) {
			bezEQ[bez_HMDL][2] = bezEQ[bez_HMCL][2]; bezEQ[bez_HMCL][2] = bezEQ[bez_HMBL][2]; 
			bezEQ[bez_HMBL][2] = bezEQ[bez_HMAL][2]*(0.5-(HMderez*0.082));
			bezEQ[bez_HMAL][2] = 0.0; bezEQ[bez_HMcycle][2] = 0.0;
		}
		X = bezEQ[bez_HMcycle][2];
		hmidL = bezEQ[bez_HMCL][2]+(bezEQ[bez_HMDL][2]*(1.0-X)*(1.0-X));
		hmidL += (bezEQ[bez_HMCL][2]*2.0*(1.0-X)*X)+(bezEQ[bez_HMBL][2]*X*X);
		hmidL *= bezier[bezierHighQ];
		highL -= hmidL; //final high and hmid
		bezEQ[bez_Mcycle][2] += Mderez;
		bezEQ[bez_MAL][2] += (hmidL * Mderez);
		if (bezEQ[bez_Mcycle][2] > Mtrim) {
			bezEQ[bez_MDL][2] = bezEQ[bez_MCL][2]; bezEQ[bez_MCL][2] = bezEQ[bez_MBL][2]; 
			bezEQ[bez_MBL][2] = bezEQ[bez_MAL][2]*(0.5-(Mderez*0.082));
			bezEQ[bez_MAL][2] = 0.0; bezEQ[bez_Mcycle][2] = 0.0;
		}
		X = bezEQ[bez_Mcycle][2];
		lmidL = bezEQ[bez_MCL][2]+(bezEQ[bez_MDL][2]*(1.0-X)*(1.0-X));
		lmidL += (bezEQ[bez_MCL][2]*2.0*(1.0-X)*X)+(bezEQ[bez_MBL][2]*X*X);
		lmidL *= bezier[bezierMidQ];
		hmidL -= lmidL; //final hmid and lmid
		bezEQ[bez_LMcycle][2] += LMderez;
		bezEQ[bez_LMAL][2] += (lmidL * LMderez);
		if (bezEQ[bez_LMcycle][2] > LMtrim) {
			bezEQ[bez_LMDL][2] = bezEQ[bez_LMCL][2]; bezEQ[bez_LMCL][2] = bezEQ[bez_LMBL][2]; 
			bezEQ[bez_LMBL][2] = bezEQ[bez_LMAL][2]*(0.5-(LMderez*0.082));
			bezEQ[bez_LMAL][2] = 0.0; bezEQ[bez_LMcycle][2] = 0.0;
		}
		X = bezEQ[bez_LMcycle][2];
		bassL = bezEQ[bez_LMCL][2]+(bezEQ[bez_LMDL][2]*(1.0-X)*(1.0-X));
		bassL += (bezEQ[bez_LMCL][2]*2.0*(1.0-X)*X)+(bezEQ[bez_LMBL][2]*X*X);
		bassL *= bezier[bezierLowQ];
		lmidL -= bassL; //final lmid and bass
		inputSampleL = (highL*bezier[bezierHigh])+(hmidL*bezier[bezierHmid])+(lmidL*bezier[bezierLmid])+(bassL*bezier[bezierBass]);
		//end BezEQ4 Post
		
		//begin Lowpass/Highpass
		if (bezier[bezierHFreq] > 0.0) {
			double lowSampleL = inputSampleL;
			for(int count = 0; count < Hpoles; count++) {
				iirHAngleL[count] = (iirHAngleL[count]*(1.0-bezier[bezierHFreq]))+((lowSampleL-iirHPositionL[count])*bezier[bezierHFreq]);
				lowSampleL = ((iirHPositionL[count]+(iirHAngleL[count]*bezier[bezierHFreq]))*(1.0-bezier[bezierHFreq]))+(lowSampleL*bezier[bezierHFreq]);
				iirHPositionL[count] = ((iirHPositionL[count]+(iirHAngleL[count]*bezier[bezierHFreq]))*(1.0-bezier[bezierHFreq]))+(lowSampleL*bezier[bezierHFreq]);
				inputSampleL -= (lowSampleL * (1.0/(double)Hpoles));//left
			} hBypass = false; //the highpass
		} else {
			if (!hBypass) {
				hBypass = true;
				for(int count = 0; count < 29; count++) {
					iirHPositionL[count] = 0.0;
					iirHAngleL[count] = 0.0;
				}//blank out highpass if jut switched off
			} 
		}		
		if (bezier[bezierLFreq] < 1.0) {
			for(int count = 0; count < Lpoles; count++) {
				iirLAngleL[count] = (iirLAngleL[count]*(1.0-bezier[bezierLFreq]))+((inputSampleL-iirLPositionL[count])*bezier[bezierLFreq]);
				inputSampleL = ((iirLPositionL[count]+(iirLAngleL[count]*bezier[bezierLFreq]))*(1.0-bezier[bezierLFreq]))+(inputSampleL*bezier[bezierLFreq]);
				iirLPositionL[count] = ((iirLPositionL[count]+(iirLAngleL[count]*bezier[bezierLFreq]))*(1.0-bezier[bezierLFreq]))+(inputSampleL*bezier[bezierLFreq]);//left
			} lBypass = false; //the lowpass
		} else {
			if (!lBypass) {
				lBypass = true;
				for(int count = 0; count < 29; count++) {
					iirLPositionL[count] = 0.0;
					iirLAngleL[count] = 0.0;
				}//blank out lowpass if just switched off
			} 
		}		
		//end Lowpass/Highpass
		
		inputSampleL *= bezier[bezierGainL];
		//applies pan section, and smoothed fader gain
		
		if (pluginMode <= 0.5) {
            double dryL = inputSampleL;
            if (inputSampleL > 1.0) inputSampleL = 1.0;
            else if (inputSampleL > 0.0) inputSampleL = -expm1((log1p(-inputSampleL) * 1.618033988749895));
            if (inputSampleL < -1.0) inputSampleL = -1.0;
            else if (inputSampleL < 0.0) inputSampleL = expm1((log1p(inputSampleL) * 1.618033988749895));
			bip[bip_dvA] = dryL - inputSampleL; // these are derivatives: raw clip is position
			bip[bip_dvB] = bip[bip_pvA]-bip[bip_dvA]; bip[bip_pvA] = bip[bip_dvA];//velocity
			bip[bip_dvC] = bip[bip_pvB]-bip[bip_dvB]; bip[bip_pvB] = bip[bip_dvB];//acceleration
			bip[bip_dvD] = bip[bip_pvC]-bip[bip_dvC]; bip[bip_pvC] = bip[bip_dvC];//jerk
			double bip_dvE = bip[bip_pvD]-bip[bip_dvD]; bip[bip_pvD] = bip[bip_dvD];//snap
			inputSampleL *= (1.0+(fabs(bip[bip_dvC])*0.0618)+(fabs(bip[bip_dvD])*-0.05982)+(fabs(bip_dvE)*0.0206));
			if (pluginMode > 0.0f) {
                inputSampleL = (inputSampleL*(1.0-(pluginMode*2.0)))+(dryL*(pluginMode*2.0));
            }
        } //engage pluginMode, channel version
		
		//begin 32 bit floating point dither
		int expon; frexpf((float)inputSampleL, &expon);
		fpd ^= fpd << 13; fpd ^= fpd >> 17; fpd ^= fpd << 5;
		inputSampleL += ((double(fpd)-uint32_t(0x7fffffff)) * 3.553e-44l * pow(2,expon+62));
		//end 32 bit floating point dither
		
		*destP = inputSampleL;
		
		sourceP += inNumChannels; destP += inNumChannels;
	}
}

