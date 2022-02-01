--- src/3rdparty/chromium/ui/views/widget/desktop_aura/desktop_screen_ozone.cc.orig	2021-11-25 09:20:12 UTC
+++ src/3rdparty/chromium/ui/views/widget/desktop_aura/desktop_screen_ozone.cc
@@ -26,7 +26,7 @@ gfx::NativeWindow DesktopScreenOzone::GetNativeWindowF
 // To avoid multiple definitions when use_x11 && use_ozone is true, disable this
 // factory method for OS_LINUX as Linux has a factory method that decides what
 // screen to use based on IsUsingOzonePlatform feature flag.
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 display::Screen* CreateDesktopScreen() {
   return new DesktopScreenOzone();
 }
