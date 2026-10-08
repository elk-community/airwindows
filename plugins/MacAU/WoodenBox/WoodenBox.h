/*
*	File:		WoodenBox.h
*	
*	Version:	1.0
* 
*	Created:	3/12/26
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
#include "WoodenBoxVersion.h"

#if AU_DEBUG_DISPATCHER
	#include "AUDebugDispatcher.h"
#endif


#ifndef __WoodenBox_h__
#define __WoodenBox_h__


#pragma mark ____WoodenBox Parameters

// parameters
static const float kDefaultValue_ParamA = 5;
static const float kDefaultValue_ParamB = 0.5;
static const float kDefaultValue_ParamC = 0.5;

static CFStringRef kParameterAName = CFSTR("Select");
static CFStringRef kParameterBName = CFSTR("Reso");
static CFStringRef kParameterCName = CFSTR("Depth");

enum {
	kParam_A =0,
	kParam_B =1,
	kParam_C =2,
	//Add your parameters here...
	kNumberOfParameters=3
};

const int d4A = 173; 
const int d4B = 82; 
const int d4C = 240; 
const int d4D = 191; 
const int d4E = 196; 
const int d4F = 257; 
const int d4G = 203; 
const int d4H = 252; 
const int d4I = 207; 
const int d4J = 203; 
const int d4K = 250; 
const int d4L = 220; 
const int d4M = 261; 
const int d4N = 235; 
const int d4O = 161; 
const int d4P = 161; 

#pragma mark ____WoodenBox
class WoodenBox : public AUEffectBase
{
public:
	WoodenBox(AudioUnit component);
#if AU_DEBUG_DISPATCHER
	virtual ~WoodenBox () { delete mDebugDispatcher; }
#endif
	
	virtual ComponentResult Reset(AudioUnitScope inScope, AudioUnitElement inElement);

	virtual OSStatus ProcessBufferLists(AudioUnitRenderActionFlags & ioActionFlags, 
						const AudioBufferList & inBuffer, AudioBufferList & outBuffer, 
						UInt32 inFramesToProcess);
	virtual UInt32 SupportedNumChannels(const AUChannelInfo ** outInfo);

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
	virtual ComponentResult		Version() { return kWoodenBoxVersion; }
	
	private: 
	int c4AL,c4BL,c4CL,c4DL,c4EL,c4FL,c4GL,c4HL;
	int c4IL,c4JL,c4KL,c4LL,c4ML,c4NL,c4OL,c4PL;		
	int c4AR,c4BR,c4CR,c4DR,c4ER,c4FR,c4GR,c4HR;
	int c4IR,c4JR,c4KR,c4LR,c4MR,c4NR,c4OR,c4PR;
	//base stereo reverb
	double b4AL[d4A+5];
	double b4BL[d4B+5];
	double b4CL[d4C+5];
	double b4DL[d4D+5];
	double b4EL[d4E+5];
	double b4FL[d4F+5];
	double b4GL[d4G+5];
	double b4HL[d4H+5];
	double b4IL[d4I+5];
	double b4JL[d4J+5];
	double b4KL[d4K+5];
	double b4LL[d4L+5];
	double b4ML[d4M+5];
	double b4NL[d4N+5];
	double b4OL[d4O+5];
	double b4PL[d4P+5];
	double b4AR[d4A+5];
	double b4BR[d4B+5];
	double b4CR[d4C+5];
	double b4DR[d4D+5];
	double b4ER[d4E+5];
	double b4FR[d4F+5];
	double b4GR[d4G+5];
	double b4HR[d4H+5];
	double b4IR[d4I+5];
	double b4JR[d4J+5];
	double b4KR[d4K+5];
	double b4LR[d4L+5];
	double b4MR[d4M+5];
	double b4NR[d4N+5];
	double b4OR[d4O+5];
	double b4PR[d4P+5];
	double g4AL,g4BL,g4CL,g4DL,g4DR,g4HR,g4LR,g4PR;
	//changed letter is the dual mono, with rearranged grid
	
	enum {
		bez_AL,
		bez_AR,
		bez_BL,
		bez_BR,
		bez_CL,
		bez_CR,	
		bez_SampL,
		bez_SampR,
		bez_cycle,
		bez_total
	}; //the new undersampling. bez signifies the bezier curve reconstruction
	double bez[bez_total];
		
	int shortA;
	int shortB;
	int shortC;
	int shortD;
	int shortE;
	int shortF;
	int shortG;
	int shortH;
	int shortI;
	int shortJ;
	int shortK;
	int shortL;
	int shortM;
	int shortN;
	int shortO;
	int shortP;
	
	int prevclearcoat;
	uint32_t fpdL;
	uint32_t fpdR;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


#endif