#pragma once
#include "XPLUM_MACRO/MACRO_INITIALIZATION.h"

#define MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD01(PARAM03_ITC_INIT_PARAM1, PARAM02_ITC_NAME, PARAM01_ITC_TYPE) MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE (PARAM01_ITC_TYPE, PARAM02_ITC_NAME, PARAM03_ITC_INIT_PARAM1)
#define MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE_OVERLOAD99(DROP, PARAM02_ITC_NAME, PARAM01_ITC_TYPE, PARAM03_ITC_INIT_PARAM...) MACRO_XPLUM_AUTO_INIT_OBJECT_INSTANCE (PARAM01_ITC_TYPE, PARAM02_ITC_NAME, PARAM03_ITC_INIT_PARAM)
#define MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE_OVERLOAD01(PARAM02_VALUE_NAME, PARAM01_REFER_NAME) MACRO_XPLUM_AUTO_INIT_REFERENCE_VALUE (PARAM01_REFER_NAME, PARAM02_VALUE_NAME)
#define MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY_OVERLOAD01(PARAM02_ARRAY_NAME, PARAM01_REFER_NAME) MACRO_XPLUM_AUTO_INIT_REFERENCE_ARRAY (PARAM01_REFER_NAME, PARAM02_ARRAY_NAME)
