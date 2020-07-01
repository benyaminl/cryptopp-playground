# This's a CryptoPP PlayGround!

This's a playground of CryptoPP, 
It based on MSYS2 - MinGW64
The library is already inside the lib folder, no need to run make again!

The CLI build should be 
`g++ -static -o {fooApp}.exe {yourSource}.cpp -L ./lib -lcryptopp`

The cryptopp flag means for include/use the libcryptopp.dll.a  and `-static` means the code in built, not using shared library that the OS need. So any exe you build doesn't need any external lib, as the lib itself inside the exe.

Thank you for @smankusors help me give some enlightment about -static flag on gnu compiler