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
//  WLChallengeHandler.h
//  WorklightStaticLibProject
//
//  Created by Ishai Borovoy on 9/13/12.
//

#import "BaseChallengeHandler.h"
#import "WLFailResponse.h"


/**
 * You use this base class to create an IBM MobileFirst Platform Challenge Handler.
 * You must extend this class to implement your own version of an IBM MobileFirst Platform Challenge Handler, for example RemoteDisableChallengeHandler.
 */
@interface WLChallengeHandler : BaseChallengeHandler
    /**
     * Send the answer back to the request.
     */
    -(void) submitChallengeAnswer: (NSDictionary *)answer;

	/**
    * This method is called when the IBM MobileFirst Platform Server reports an authentication success.
    */
    -(void) handleSuccess: (NSDictionary *)success;
    
    /**
    *  This method is called when the IBM MobileFirst Platform Server reports an authentication failure.
    */
    -(void) handleFailure: (NSDictionary *)failure;
    
    /**
    * This method is called when the IBM MobileFirst Platform Server returns a challenge for the realm.
    */
    -(void) handleChallenge: (NSDictionary *)challenge;
@end
