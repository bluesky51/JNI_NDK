LOCAL_PATH := $(call my-dir)//指定编译的路径
include $(CLEAR_VARS)//每个新模块的开始处，清理所有的LOCAL_XXX

LOCAL_MODULE := Hello //定义了模块的名称
LOCAL_LDFLAGS := -Wl,--build-id
LOCAL_SRC_FILES := \
	/Users/bluesky/Desktop/未命名文件夹/JNI_NDK/app/src/main/jni/Hello.c \  //源代码文件

LOCAL_C_INCLUDES += /Users/bluesky/Desktop/未命名文件夹/JNI_NDK/app/src/main/jni
LOCAL_C_INCLUDES += /Users/bluesky/Desktop/未命名文件夹/JNI_NDK/app/src/debug/jni

include $(BUILD_SHARED_LIBRARY)//说明编译的是共享库及动态链接库
