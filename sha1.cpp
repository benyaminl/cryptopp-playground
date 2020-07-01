#include "cryptopp/cryptlib.h"
#include "cryptopp/sha.h"
// @see https://cryptopp.com/wiki/HexEncoder
#include <cryptopp/hex.h>
// @see https://cryptopp.com/wiki/FileSink
#include <cryptopp/files.h>
#include <iostream>

int main (int argc, char* argv[])
{
    using namespace CryptoPP;

    SHA1 hash;	
    std::cout << "Name: " << hash.AlgorithmName() << std::endl;
    std::cout << "Digest size: " << hash.DigestSize() << std::endl;
    std::cout << "Block size: " << hash.BlockSize() << std::endl;
    std::cout << "Test Digest : ABC" << std::endl;
    std::cout << "Result Digest : " ;

    HexEncoder encoder(new FileSink(std::cout));

    std::string msg = "Yoda said, Do or do not. There is no try.";
    std::string digest;
    hash.Update((const byte*)msg.data(), msg.size());
    digest.resize(hash.DigestSize());
    hash.Final((byte*)&digest[0]);

    std::cout << "Message: " << msg << std::endl;

    std::cout << "Digest: ";
    StringSource(digest, true, new Redirector(encoder));
    std::cout << std::endl;
    return 0; 
}