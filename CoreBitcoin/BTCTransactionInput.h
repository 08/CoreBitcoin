// Oleg Andreev <oleganza@gmail.com>

#import <Foundation/Foundation.h>

@class BTCScript;

// Transaction input (aka "txin") represents a reference to another transaction's output.
// Reference is defined by tx hash + tx output index.
// Signature script is used to prove ownership of the corresponding tx output.
// Sequence is used to require different signatures when tx is updated. It is only relevant when tx lockTime > 0.
@interface BTCTransactionInput : NSObject

// Hash of the previous transaction.
@property(nonatomic) NSData* previousHash;

// Index of the previous transaction's output.
@property(nonatomic) uint32_t previousIndex;

// Script that proves ownership of the previous transaction output.
@property(nonatomic) BTCScript* signatureScript;

// Input sequence. Default is maximum value 0xFFFFFFFF.
// Sequence is used to require different signatures when tx is updated. It is only relevant when tx lockTime > 0.
@property(nonatomic) uint32_t sequence;

// Serialized binary representation of the txin.
@property(nonatomic, readonly) NSData* data;

// Parses tx input from a data buffer.
- (id) initWithData:(NSData*)data;

// Read tx input from the stream.
- (id) initWithStream:(NSInputStream*)stream;

// Constructs transaction input from a dictionary representation
- (id) initWithDictionary:(NSDictionary*)dictionary;

// Returns a dictionary representation suitable for encoding in JSON or Plist.
- (NSDictionary*) dictionaryRepresentation;

// Returns YES if this txin generates new coins.
- (BOOL) isCoinbase;

@end
