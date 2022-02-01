--- src/3rdparty/chromium/media/capture/video/create_video_capture_device_factory.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/media/capture/video/create_video_capture_device_factory.cc
@@ -11,7 +11,7 @@
 #include "media/capture/video/fake_video_capture_device_factory.h"
 #include "media/capture/video/file_video_capture_device_factory.h"
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "media/capture/video/linux/video_capture_device_factory_linux.h"
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
 #include "media/capture/video/chromeos/public/cros_features.h"
@@ -80,7 +80,7 @@ CreateChromeOSVideoCaptureDeviceFactory(
 std::unique_ptr<VideoCaptureDeviceFactory>
 CreatePlatformSpecificVideoCaptureDeviceFactory(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner) {
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   return std::make_unique<VideoCaptureDeviceFactoryLinux>(ui_task_runner);
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
   return CreateChromeOSVideoCaptureDeviceFactory(ui_task_runner);
