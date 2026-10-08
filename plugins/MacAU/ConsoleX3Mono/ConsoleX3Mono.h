/*
*	File:		ConsoleX3Mono.h
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
#include "AUEffectBase.h"
#include "ConsoleX3MonoVersion.h"

#if AU_DEBUG_DISPATCHER
	#include "AUDebugDispatcher.h"
#endif


#ifndef __ConsoleX3Mono_h__
#define __ConsoleX3Mono_h__


#pragma mark ____ConsoleX3Mono Parameters

// parameters

static const float kDefaultValue_ParamHIG = 0.5;
static const float kDefaultValue_ParamHMG = 0.5;
static const float kDefaultValue_ParamLMG = 0.5;
static const float kDefaultValue_ParamBSG = 0.5;
static const float kDefaultValue_ParamHIF = 0.5;
static const float kDefaultValue_ParamHMF = 0.5;
static const float kDefaultValue_ParamLMF = 0.5;
static const float kDefaultValue_ParamBSF = 0.5;

static const float kDefaultValue_ParamTHR = 1.0;
static const float kDefaultValue_ParamATK = 0.382;
static const float kDefaultValue_ParamRLS = 0.618;
static const float kDefaultValue_ParamRAT = 1.0;

static const float kDefaultValue_ParamTRM = 0.5;
static const float kDefaultValue_ParamMDE = 0.0;
static const float kDefaultValue_ParamSMO = 0.5;
static const float kDefaultValue_ParamMOR = 0.0;

static const float kDefaultValue_ParamLOP = 1.0;
static const float kDefaultValue_ParamLPQ = 0.0;
static const float kDefaultValue_ParamHIP = 0.0;
static const float kDefaultValue_ParamHPQ = 0.0;

static const float kDefaultValue_ParamFAD = 1.0;



static CFStringRef kParameterHIGUnit = CFSTR("eq");
static CFStringRef kParameterHIGName = CFSTR("High");
static CFStringRef kParameterHMGName = CFSTR("HMid");
static CFStringRef kParameterLMGName = CFSTR("LMid");
static CFStringRef kParameterBSGName = CFSTR("Bass");
static CFStringRef kParameterHIFUnit = CFSTR("freq");
static CFStringRef kParameterHIFName = CFSTR("HighF");
static CFStringRef kParameterHMFName = CFSTR("HMidF");
static CFStringRef kParameterLMFName = CFSTR("LMidF");
static CFStringRef kParameterBSFName = CFSTR("BassF");

static CFStringRef kParameterTHRUnit = CFSTR("comp");
static CFStringRef kParameterTHRName = CFSTR("Thresh");
static CFStringRef kParameterATKName = CFSTR("Attack");
static CFStringRef kParameterRLSName = CFSTR("Release");
static CFStringRef kParameterRATName = CFSTR("Inv/Wet");

static CFStringRef kParameterTRMUnit = CFSTR("trim");
static CFStringRef kParameterTRMName = CFSTR("Input");
static CFStringRef kParameterMDEUnit = CFSTR("mode");
static CFStringRef kParameterMDEName = CFSTR("Cha/Bus");
static CFStringRef kParameterSMOName = CFSTR("Smooth");
static CFStringRef kParameterMORUnit = CFSTR("tape");
static CFStringRef kParameterMORName = CFSTR("More");

static CFStringRef kParameterLOPName = CFSTR("Lowpass");
static CFStringRef kParameterLPQName = CFSTR("LowpasQ");
static CFStringRef kParameterHIPName = CFSTR("Hipass");
static CFStringRef kParameterHPQName = CFSTR("HipassQ");

static CFStringRef kParameterFADUnit = CFSTR("fader");
static CFStringRef kParameterFADName = CFSTR("Fader");

enum {
	
	kParam_HIG =0,
	kParam_HMG =1,
	kParam_LMG =2,
	kParam_BSG =3,
	kParam_HIF =4,
	kParam_HMF =5,
	kParam_LMF =6,
	kParam_BSF =7,
	
	kParam_THR =8,
	kParam_ATK =9,
	kParam_RLS =10,
	kParam_RAT =11,
	
	kParam_TRM =12,
	kParam_MDE =13,
	kParam_SMO =14,
	kParam_MOR =15,
	
	kParam_LOP =16,
	kParam_LPQ =17,
	kParam_HIP =18,
	kParam_HPQ =19,
	
	kParam_FAD =20,
	//Add your parameters here...
	kNumberOfParameters=21
};

#pragma mark ____ConsoleX3Mono
class ConsoleX3Mono : public AUEffectBase
{
public:
	ConsoleX3Mono(AudioUnit component);
#if AU_DEBUG_DISPATCHER
	virtual ~ConsoleX3Mono () { delete mDebugDispatcher; }
#endif
	
	virtual AUKernelBase *		NewKernel() { return new ConsoleX3MonoKernel(this); }
	
	virtual	ComponentResult		GetParameterValueStrings(AudioUnitScope			inScope,
														 AudioUnitParameterID		inParameterID,
														 CFArrayRef *			outStrings);
    
	virtual	ComponentResult		GetParameterInfo(AudioUnitScope			inScope,
												 AudioUnitParameterID	inParameterID,
												 AudioUnitParameterInfo	&outParameterInfo);
    
	virtual ComponentResult		GetPropertyInfo(AudioUnitPropertyID		inID,
												AudioUnitScope			inScope,
												AudioUnitElement		inElement,
												UInt32 &			outDataSize,
												Boolean	&			outWritable );
	
	virtual ComponentResult		GetProperty(AudioUnitPropertyID inID,
											AudioUnitScope 		inScope,
											AudioUnitElement 		inElement,
											void *			outData);
	
	virtual ComponentResult    Initialize();
	virtual bool				SupportsTail () { return true; }
    virtual Float64				GetTailTime() {return (1.0/GetSampleRate())*0.0;} //in SECONDS! gsr * a number = in samples
    virtual Float64				GetLatency() {return (1.0/GetSampleRate())*0.0;}	// in SECONDS! gsr * a number = in samples
	
	/*! @method Version */
	virtual ComponentResult		Version() { return kConsoleX3MonoVersion; }
	
    
	
protected:
		class ConsoleX3MonoKernel : public AUKernelBase		// most of the real work happens here
	{
public:
		ConsoleX3MonoKernel(AUEffectBase *inAudioUnit )
		: AUKernelBase(inAudioUnit)
	{
	}
		
		// *Required* overides for the process method for this effect
		// processes one channel of interleaved samples
        virtual void 		Process(	const Float32 	*inSourceP,
										Float32		 	*inDestP,
										UInt32 			inFramesToProcess,
										UInt32			inNumChannels,
										bool			&ioSilence);
		
        virtual void		Reset();
		
		private: 
		enum {
			bezierHigh_A,bezierHigh_B,bezierHigh_C,bezierHigh,
			bezierHmid_A,bezierHmid_B,bezierHmid_C,bezierHmid,
			bezierLmid_A,bezierLmid_B,bezierLmid_C,bezierLmid,
			bezierBass_A,bezierBass_B,bezierBass_C,bezierBass,
			bezierHighQ_A,bezierHighQ_B,bezierHighQ_C,bezierHighQ,
			bezierMidQ_A,bezierMidQ_B,bezierMidQ_C,bezierMidQ,
			bezierLowQ_A,bezierLowQ_B,bezierLowQ_C,bezierLowQ,
			bezierThresh_A,bezierThresh_B,bezierThresh_C,bezierThresh,
			bezierRatio_A,bezierRatio_B,bezierRatio_C,bezierRatio,
			bezierMore_A,bezierMore_B,bezierMore_C,bezierMore,
			bezierLFreq_A,bezierLFreq_B,bezierLFreq_C,bezierLFreq,
			bezierHFreq_A,bezierHFreq_B,bezierHFreq_C,bezierHFreq,
			bezierGainL_A,bezierGainL_B,bezierGainL_C,bezierGainL,
			bezier_cycle,
			bezier_total
		}; //control smoothing as basic use of bezier curves
		double bezier[bezier_total];
		
		enum {
			bez_HMAL, bez_HMBL, bez_HMCL, bez_HMDL,
			bez_MAL, bez_MBL, bez_MCL, bez_MDL,
			bez_LMAL, bez_LMBL, bez_LMCL, bez_LMDL,
			bez_HMcycle, bez_Mcycle, bez_LMcycle,
			bez_EQtotal
		}; //the new undersampling. bez signifies the bezier curve reconstruction
		double bezEQ[bez_EQtotal][3];
		
		enum {
			bez_A,
			bez_B,
			bez_C,
			bez_Ctrl,
			bez_cycle,
			bez_min,
			bez_comp,
			bez_total
		}; //the new undersampling. bez signifies the bezier curve reconstruction
		double bezComp[bez_total];
		//Dynamics3
		
		double iirHPositionL[29];
		double iirHAngleL[29];
		bool hBypass;
		double iirLPositionL[29];
		double iirLAngleL[29];
		bool lBypass;
		//Cabs2
		
		enum {
			bip_dvAA, bip_dvAB, bip_dvAC, bip_dvAD, bip_pvAA, bip_pvAB, bip_pvAC, bip_pvAD,
			bip_dvA, bip_dvB, bip_dvC, bip_dvD, bip_pvA, bip_pvB, bip_pvC, bip_pvD,
			bip_total //each distortion section can have one of these, it stacks well
		}; //not remotely elliptic BLEP antialiasing, instead it is derivative BIP :D
		double bip[bip_total];
		
		uint32_t fpd;
	};
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#endif