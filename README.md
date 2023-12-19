This is a sample Android project to demonstrate how to use OpenXR to make a VR Application. Here are the steps you need to run this project

1. Install the OpenXR Mobile SDK from [here](https://developer.oculus.com/downloads/package/oculus-openxr-mobile-sdk/)
2. Install Android Studio and open the sdk as a project
3. Make sure the NDK is installed. You can check by opening the settings menu at the top right, clicking on the SDK Manager option, going to SDK Tools, and then installing the NDK by checking the box.
4. This project uses Gradle 7.4.2. You can set the gradle version by going to build.gradle and changing the classpath line to
```
dependencies {
    classpath 'com.android.tools.build:gradle:7.4.2'
}
```
5. This project uses Java 17. You can set this by going to the Find Action menu and searching up `Change Gradle Location`. In this menu, install/select Java 17 as the Gradle JDK
6. Clone this repository into the XrSamples folder. Then go to `settings.gradle` and add these lines
```
include ':',
	'XrSamples:XrAppBase:Projects:Android',
	'XrSamples:XrBodyFaceEyeSocial:Projects:Android',
	':XrSamples:XrBodyTrackingFB:Projects:Android',
	':XrSamples:XrColorSpaceFB:Projects:Android',
	':XrSamples:XrCompositor_NativeActivity:Projects:Android',
	'XrSamples:XrControllers:Projects:Android',
	'XrSamples:XrEyeTrackingSocialFB:Projects:Android',
	'XrSamples:XrFaceTrackingFB:Projects:Android',
	'XrSamples:XrHandDataSource:Projects:Android',
	'XrSamples:XrHandsAndControllers:Projects:Android',
	'XrSamples:XrHandsFB:Projects:Android',
	'XrSamples:XrInput:Projects:Android',
	'XrSamples:XrKeyboard:Projects:Android',
	'XrSamples:XrPassthrough:Projects:Android',
	'XrSamples:XrSceneModel:Projects:Android',
	'XrSamples:XrSpaceWarp:Projects:Android',
	'XrSamples:XrSpatialAnchor:Projects:Android',
	'XrSamples:XrVirtualKeyboard:Projects:Android',
	'XrSamples:XrHelloWorld:Projects:Android'
```
7. Perform a gradle sync and build your project.

After this, you should be good to go!
