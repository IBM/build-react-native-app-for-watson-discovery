/**
	Licensed Materials - Property of IBM

	(C) Copyright 2015 IBM Corp.

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

#import <Foundation/Foundation.h>
#import "WLSecurityCommonUtils.h"

/**
 IBM MobileFirst Platform Security Utilities.
 @since IBM Worklight V6.2.0
 */

extern NSString * const WLClientErrorDomain;
@interface WLSecurityUtils : NSObject

/**
 Generates a key by using the PBKDF2 algorithm.
 @param pass The password that is used to generate the key
 @param salt The salt that is used to generate the key
 @param iterations The number of iterations that is passed to the key generation algorithm
 @param error Error
 @return The generated key.
 @since IBM Worklight V6.2.0
 */
+(NSString*) generateKeyWithPassword: (NSString *) pass
                             andSalt: (NSString *) salt
                       andIterations: (NSInteger) iterations
                               error: (NSError**) error;

/**
 Encrypts text with a key.
 @param text The text to encrypt
 @param key The key used for encryption
 @param error Error
 @return An NSDictionary with the cipher text (ct), the IV (iv), the source (src) and the version (v).
 @since IBM Worklight V6.2.0
 */
+(NSDictionary*) encryptText: (NSString*) text
                     withKey: (NSString*) key
                       error: (NSError**) error;

/**
 Decrypts a dictionary that contains: src (source), v (version), ct (cipher text) and the iv (initialization vector).
 @param ciphertext The encrypted text to decrypt
 @param key The key used for decryption
 @param encryptedObj NSDictionary that is returned from encryptText:withKey:error:
 @param error Error
 @return The decrypted text
 @since IBM Worklight V6.2.0
 */
+(NSString*) decryptWithKey: (NSString*) key
              andDictionary:(NSDictionary*) encryptedObj
                      error: (NSError**) error;

/**
 Gets a random string from the server.
 @param bytes Number of bytes that are used to generate the random string (maximum 64 bytes)
 @param timeout The time to wait for the network request to finish
 @param handler Called when the request finished, the data field will have the random string (NSUTF8StringEncoding)
 @since IBM Worklight V6.2.0
 */
+(void) getRandomStringFromServerWithBytes:(int)bytes
                                   timeout:(int)timeout
                         completionHandler:(void (^)(NSURLResponse* response, NSData* data, NSError* connectionError)) handler;

/**
 Generates a random string locally.
 @param bytes Number of bytes that is used to generate the random string
 @return The random string, nil if the operation fails
 @since IBM Worklight V6.2.0
 */
+(NSString*) generateRandomStringWithBytes:(int) bytes;

/**
 Encodes data to an NSString with Base64 encoding.
 @param data Data
 @param length Length of the input
 @return Base64 encoded NSString
 @since IBM Worklight V6.2.0
 */
+ (NSString*) base64StringFromData:(NSData*) data
                             length:(int) length;

/**
 Reads Base64 encoded file and writes decoded output to output file
 @param handleInput Handle to input file; the caller is responsible for closing the file
 @param outputFileName Full path to output file
 @since IBM Worklight V6.2.0
 */
+(void) decodeBase64WithFiles:(NSFileHandle*) handleInput output:(NSString*) outputFileName;

+(NSData*) _decodeBase64WithString:(NSString*) strBase64;

+ (BOOL) verifyPayloadWithSignedData:(NSData *)payloadData signedDataBase64:(NSString*)dataBase64;
+ (BOOL) checkPublicKeyValidity;
+ (BOOL)verifySignature:(NSData *)plainText secKeyRef:(SecKeyRef)publicKey signature:(NSData *)sig;

+ (NSData *) sha1FromFile:(NSString *)path;
+ (NSData *) sha256FromFile:(NSString *)path;

+(NSString *)readSignatureWithLength:(int)length withPath:(NSString*) path;

+(int)padFileLastBytes:(int)nBytesFromEndOfFile withPaddingChar:(char)padd filePath:(NSString*) path;

+(void) enableOSNativeEncryption:(BOOL) enable;

@end
