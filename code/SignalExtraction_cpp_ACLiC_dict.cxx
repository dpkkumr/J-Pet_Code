// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIrundImediadIdpkdINowydIcodedISignalExtraction_cpp_ACLiC_dict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualifies STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "/run/media/dpk/Nowy/code/SignalExtraction.cpp"

// Header files passed via #pragma extra_include

namespace {
  void TriggerDictionaryInitialization_SignalExtraction_cpp_ACLiC_dict_Impl() {
    static const char* headers[] = {
"SignalExtraction.cpp",
0
    };
    static const char* includePaths[] = {
"/usr/include/root",
"/usr/share/root",
"/usr/share/root/cling",
"/usr/include/root",
"/usr/include/freetype2",
"/run/media/dpk/Nowy/code/",
"/usr/include/root",
"/run/media/dpk/Nowy/code/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "SignalExtraction_cpp_ACLiC_dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "SignalExtraction_cpp_ACLiC_dict dictionary payload"

#ifndef __ACLIC__
  #define __ACLIC__ 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "SignalExtraction.cpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"SignalExtraction", payloadCode, "@",
"chNb", payloadCode, "@",
"checkIfFileExists", payloadCode, "@",
"convertIntToString", payloadCode, "@",
"exec", payloadCode, "@",
"generateGraphs", payloadCode, "@",
"makeFilePath", payloadCode, "@",
"makeSignalPath", payloadCode, "@",
"readDataFile", payloadCode, "@",
"setTitleofGraphs", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("SignalExtraction_cpp_ACLiC_dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_SignalExtraction_cpp_ACLiC_dict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_SignalExtraction_cpp_ACLiC_dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_SignalExtraction_cpp_ACLiC_dict() {
  TriggerDictionaryInitialization_SignalExtraction_cpp_ACLiC_dict_Impl();
}
