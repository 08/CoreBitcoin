// Oleg Andreev <oleganza@gmail.com>

#import <Foundation/Foundation.h>

// Base58 is used for compact human-friendly representation of Bitcoin addresses and private keys.
// Typically Base58-encoded text also contains a checksum.
// Addresses look like 19FGfswVqxNubJbh1NW8A4t51T9x9RDVWQ
// Private keys look like 5KQntKuhYWSRXNqp2yhdXzjekYAR7US3MT1715Mbv5CyUKV6hVe
//
// Here is what Satoshi said about Base58:
// Why base-58 instead of standard base-64 encoding?
// - Don't want 0OIl characters that look the same in some fonts and
//      could be used to create visually identical looking account numbers.
// - A string with non-alphanumeric characters is not as easily accepted as an account number.
// - E-mail usually won't line-break if there's no punctuation to break at.
// - Double-clicking selects the whole number as one word if it's all alphanumeric.


// TODO: use NS+BTCBase58.h instead for categories and change this API to be function-based.


@interface NSString (Base58)

// Returns data for Base58 string without checksum
// Data is mutable so you can clear sensitive information as soon as possible.
- (NSMutableData*) dataFromBase58;

// Returns data for Base58 string with checksum
- (NSMutableData*) dataFromBase58Check;

@end

@interface NSMutableData (Base58)

// Returns data for Base58 string without checksum
// Data is mutable so you can clear sensitive information as soon as possible.
+ (NSMutableData*) dataFromBase58CString:(const char*)cstring;

// Returns data for Base58 string with checksum
+ (NSMutableData*) dataFromBase58CheckCString:(const char*)cstring;

@end

@interface NSData (Base58)

// String in Base58 without checksum, you need to free it yourself.
// It's mutable so you can clear it securely yourself.
- (char*) base58CString;

// String in Base58 with checksum, you need to free it yourself.
// It's mutable so you can clear it securely yourself.
- (char*) base58CheckCString;

// String in Base58 without checksum
- (NSString*) base58String;

// String in Base58 with checksum
- (NSString*) base58CheckString;

@end
