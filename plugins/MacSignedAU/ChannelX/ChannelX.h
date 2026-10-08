/*
*	File:		ChannelX.h
*	
*	Version:	1.0
* 
*	Created:	7/15/26
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
#include "ChannelXVersion.h"

#if AU_DEBUG_DISPATCHER
	#include "AUDebugDispatcher.h"
#endif


#ifndef __ChannelX_h__
#define __ChannelX_h__


#pragma mark ____ChannelX Parameters

// parameters
static CFStringRef kParameterOneName = CFSTR("Console Type");
static const int kNeve = 1;
static const int kAPI = 2;
static const int kSSL = 3;
static const int kTeac = 4;
static const int kMackie = 5;
static const int kDefaultValue_ParamOne = kNeve;

static CFStringRef kParameterTwoName = CFSTR("Drive");
static const float kDefaultValue_ParamTwo = 0.0;

static CFStringRef kParameterThreeName = CFSTR("Output");
static const float kDefaultValue_ParamThree = 1.0;


static CFStringRef kMenuItem_Neve = CFSTR ("Neve");
static CFStringRef kMenuItem_API = CFSTR ("API");
static CFStringRef kMenuItem_SSL = CFSTR ("SSL");
static CFStringRef kMenuItem_Teac = CFSTR ("Teac");
static CFStringRef kMenuItem_Mackie = CFSTR ("Mackie");
//Alter the name if desired, but using the plugin name is a start

enum {
	kParam_One =0,
	kParam_Two =1,
	kParam_Three =2,
	//Add your parameters here...
	kNumberOfParameters=3
};

#pragma mark ____ChannelX
class ChannelX : public AUEffectBase
{
public:
	ChannelX(AudioUnit component);
#if AU_DEBUG_DISPATCHER
	virtual ~ChannelX () { delete mDebugDispatcher; }
#endif
	
	virtual AUKernelBase *		NewKernel() { return new ChannelXKernel(this); }
	
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
	virtual ComponentResult		Version() { return kChannelXVersion; }
	
    
	
protected:
		class ChannelXKernel : public AUKernelBase		// most of the real work happens here
	{
public:
		ChannelXKernel(AUEffectBase *inAudioUnit )
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
		double lastSampleA, lastSampleB, lastSampleC;
		double rbSampleLA;
		double rbSampleLB;
		bool flip;
		enum {
			bip_dvA, bip_dvB, bip_dvC, bip_dvD, bip_pvA, bip_pvB, bip_pvC, bip_pvD,
			bip_drbLA, bip_drbLB, bip_drbLC, bip_drbLD,
			bip_praLA, bip_praLB, bip_praLC, bip_praLD,
			bip_prbLA, bip_prbLB, bip_prbLC, bip_prbLD,
			bip_total //each distortion section can have one of these, it stacks well
		}; //not remotely elliptic BLEP antialiasing, instead it is derivative BIP :D
		double bip[bip_total];
		uint32_t fpd;
	};
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#endif