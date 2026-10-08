/* ========================================
 *  FastDistance - FastDistance.h
 *  Copyright (c) airwindows, Airwindows uses the MIT license
 * ======================================== */

#ifndef __FastDistance_H
#include "FastDistance.h"
#endif

AudioEffect* createEffectInstance(audioMasterCallback audioMaster) {return new FastDistance(audioMaster);}

FastDistance::FastDistance(audioMasterCallback audioMaster) :
    AudioEffectX(audioMaster, kNumPrograms, kNumParameters)
{
	A = 0.0;

	firstDryL = firstAvgL = 0.0f;
	lsA = lsB = lsC = lsD = lsE = lsF = lsG = lsH = lsI = lsJ = lsK = lsL = lsM = 0.0f;
	lsN = lsO = lsP = lsQ = lsR = lsS = lsT = lsU = lsV = lsW = lsX = lsY = lsZ = 0.0f;
	lsa = lsb = lsc = lsd = lse = lsf = lsg = lsh = lsi = lsj = lsk = lsl = lsm = 0.0f;
	lsn = lso = lsp = lsq = lsr = lss = lst = lsu = lsv = lsw = lsx = lsy = lsz = 0.0f;	
	firstDryR = firstAvgR = 0.0f;
	rsA = rsB = rsC = rsD = rsE = rsF = rsG = rsH = rsI = rsJ = rsK = rsL = rsM = 0.0f;
	rsN = rsO = rsP = rsQ = rsR = rsS = rsT = rsU = rsV = rsW = rsX = rsY = rsZ = 0.0f;
	rsa = rsb = rsc = rsd = rse = rsf = rsg = rsh = rsi = rsj = rsk = rsl = rsm = 0.0f;
	rsn = rso = rsp = rsq = rsr = rss = rst = rsu = rsv = rsw = rsx = rsy = rsz = 0.0f;	
	
	prevDistance = 0;
	pointCycle = pointAL = pointBL = pointAR = pointBR = 0.0f;
	
	fpdL = 1.0; while (fpdL < 16386) fpdL = rand()*UINT32_MAX;
	fpdR = 1.0; while (fpdR < 16386) fpdR = rand()*UINT32_MAX;
	//this is reset: values being initialized only once. Startup values, whatever they are.
	
    _canDo.insert("plugAsChannelInsert"); // plug-in can be used as a channel insert effect.
    _canDo.insert("plugAsSend"); // plug-in can be used as a send effect.
    _canDo.insert("x2in2out"); 
    setNumInputs(kNumInputs);
    setNumOutputs(kNumOutputs);
    setUniqueID(kUniqueId);
    canProcessReplacing();     // supports output replacing
    canDoubleReplacing();      // supports double precision processing
	programsAreChunks(true);
    vst_strncpy (_programName, "Default", kVstMaxProgNameLen); // default program name
}

FastDistance::~FastDistance() {}
VstInt32 FastDistance::getVendorVersion () {return 1000;}
void FastDistance::setProgramName(char *name) {vst_strncpy (_programName, name, kVstMaxProgNameLen);}
void FastDistance::getProgramName(char *name) {vst_strncpy (name, _programName, kVstMaxProgNameLen);}
//airwindows likes to ignore this stuff. Make your own programs, and make a different plugin rather than
//trying to do versioning and preventing people from using older versions. Maybe they like the old one!

static float pinParameter(float data)
{
	if (data < 0.0f) return 0.0f;
	if (data > 1.0f) return 1.0f;
	return data;
}

VstInt32 FastDistance::getChunk (void** data, bool isPreset)
{
	float *chunkData = (float *)calloc(kNumParameters, sizeof(float));
	chunkData[0] = A;
	/* Note: The way this is set up, it will break if you manage to save settings on an Intel
	 machine and load them on a PPC Mac. However, it's fine if you stick to the machine you 
	 started with. */
	
	*data = chunkData;
	return kNumParameters * sizeof(float);
}

VstInt32 FastDistance::setChunk (void* data, VstInt32 byteSize, bool isPreset)
{	
	float *chunkData = (float *)data;
	A = pinParameter(chunkData[0]);
	/* We're ignoring byteSize as we found it to be a filthy liar */
	
	/* calculate any other fields you need here - you could copy in 
	 code from setParameter() here. */
	return 0;
}

void FastDistance::setParameter(VstInt32 index, float value) {
    switch (index) {
        case kParamA: A = value; break;
        default: throw; // unknown parameter, shouldn't happen!
    }
}

float FastDistance::getParameter(VstInt32 index) {
    switch (index) {
        case kParamA: return A; break;
        default: break; // unknown parameter, shouldn't happen!
    } return 0.0; //we only need to update the relevant name, this is simple to manage
}

void FastDistance::getParameterName(VstInt32 index, char *text) {
    switch (index) {
        case kParamA: vst_strncpy (text, "Distnce", kVstMaxParamStrLen); break;
        default: break; // unknown parameter, shouldn't happen!
    } //this is our labels for displaying in the VST host
}

void FastDistance::getParameterDisplay(VstInt32 index, char *text) {
    switch (index) {
        case kParamA: float2string (A, text, kVstMaxParamStrLen); break;
        default: break; // unknown parameter, shouldn't happen!
	} //this displays the values and handles 'popups' where it's discrete choices
}

void FastDistance::getParameterLabel(VstInt32 index, char *text) {
    switch (index) {
        case kParamA: vst_strncpy (text, "", kVstMaxParamStrLen); break;
		default: break; // unknown parameter, shouldn't happen!
    }
}

VstInt32 FastDistance::canDo(char *text) 
{ return (_canDo.find(text) == _canDo.end()) ? -1: 1; } // 1 = yes, -1 = no, 0 = don't know

bool FastDistance::getEffectName(char* name) {
    vst_strncpy(name, "FastDistance", kVstMaxProductStrLen); return true;
}

VstPlugCategory FastDistance::getPlugCategory() {return kPlugCategEffect;}

bool FastDistance::getProductString(char* text) {
  	vst_strncpy (text, "airwindows FastDistance", kVstMaxProductStrLen); return true;
}

bool FastDistance::getVendorString(char* text) {
  	vst_strncpy (text, "airwindows", kVstMaxVendorStrLen); return true;
}
