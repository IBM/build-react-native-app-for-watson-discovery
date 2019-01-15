IBM MobileFirst Platform Foundation iOS SDK
===

This package contains the required native components for your application to interact with IBM
MobileFirst Platform Foundation or IBM MobileFirst Platform Foundation for iOS. IBM MobileFirst Platform Foundation and IBM MobileFirst Platform Foundation for iOS provide an on-premises backend server and infrastructure
for managing MobileFirst applications. The SDK manages all of the communication and security integration between your iOS mobile app and IBM MobileFirst Platform Foundation or IBM MobileFirst Platform Foundation for iOS servers.


###Installing and using the SDK
Install the SDK with [CocoaPods](http://cocoapods.org/).  To install CocoaPods, see [CocoaPods Getting Started](http://guides.cocoapods.org/using/getting-started.html#getting-started). 
The SDK is downloaded when you run the pod install command, after you specify the SDK source path in your podfile.
For more information, see:
- (MobileFirst Platform Foundation) [Developing a new iOS native application with CocoaPods ](https://mobilefirstplatform.ibmcloud.com/tutorials/en/foundation/8.0/application-development/sdk/ios/#adding-the-mobilefirst-native-sdk


###SDK contents
The IBM MobileFirst Platform Foundation iOS SDK consists of a collection of pods, available through CocoaPods, that you can add to your project.
The pods correspond to core and optional functions that are exposed by IBM MobileFirst Platform Foundation or 
IBM MobileFirst Platform Foundation for iOS.  The SDK contains the following pods:

- **IBMMobileFirstPlatformFoundation**: Provides core functionality. It implements client-server connections, handles security, accesses server resources and handles their responses. Includes iOS and watchOS2 support.
- **IBMMobileFirstPlatformFoundationJSONStore**: Enables the JSONStore feature for iOS native MobileFirst apps. It contains JSONStore native APIs.
- **IBMMobileFirstPlatformFoundationPush**: Provides support for push notifications from the server.
- **IBMMobileFirstPlatformFoundationLiveUpdate**: Enables LiveUpdate feature for iOS native MobileFirst app where user can implement feature toggling, A/B testing, feature segmentation and more. 
- **IBMMobileFirstPlatformFoundationOpenSSLUtils**: Provides support for encryption and decryption using OpenSSL.

Each pod handles one or more iOS frameworks. All of the pods depend on, include and load the IBMMobileFirstPlatformFoundation pod/framework. 


###Supported iOS & MFP Server levels
- iOS 8 and above
- This version of the cocoapod requires a minimum MobileFirst server version of 8.0.0.00.20170220-124830

###Getting started 

Get started with the following tutorials: 

- [Quickly Get Started](https://mobilefirstplatform.ibmcloud.com)

###Learning More
   * Visit [IBM MobileFirst Platform Foundation Dev Center](https://mobilefirstplatform.ibmcloud.com).

###Connect with IBM MobileFirst
[Web](http://www.ibm.com/mobilefirst) |
[Twitter](http://twitter.com/ibmmobile/) |
[Blog](http://asmarterplanet.com/mobile-enterprise) |
[Facebook](http://www.facebook.com/ibmMobile/) |
[Linkedin](http://www.linkedin.com/groups/IBM-Mobile-4579117/about)


Copyright 2017 IBM Corp.

   IBM - IBM MobileFirst Platform Foundation v8.0 license agreement

       https://mobilefirstplatform.ibmcloud.com/licenses/ipla

[Terms of Use](https://mobilefirstplatform.ibmcloud.com/licenses/ipla)
