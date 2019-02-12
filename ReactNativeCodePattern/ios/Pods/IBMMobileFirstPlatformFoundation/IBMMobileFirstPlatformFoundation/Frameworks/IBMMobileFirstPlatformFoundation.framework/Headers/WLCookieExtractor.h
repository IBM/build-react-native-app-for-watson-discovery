/**
	Licensed Materials - Property of IBM

	(C) Copyright 2015 IBM Corp.

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

//
//  WLCookieExtractor.h
//  Worklight SDK
//
//  Created by Benny Weingarten on 11/24/10.
//  Copyright (C) Worklight Ltd. 2006-2012.  All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * This class provides access to external cookies that WLClient can use when it issues requests to the IBM MobileFirst Platform Server. You use this class to share session cookies between a web view and a natively implemented page.
 * This class has no API methods. An object of this class must be passed as a parameter to <code>wlConnectWithDelegate:cookieExtractor</code>.
 */
@interface WLCookieExtractor : NSObject {

}

-(NSDictionary *)getCookies;


@end
