
#include <iostream>


using namespace std;



class Block {

        public :

                uint32_t   nonce;
                // this not good we need uint256 bcz we use sha256  . vector<unsigned cahr> 
                string     hash;

                string  PrevBlockHach ;

                uint32_t timestamp;

                


}