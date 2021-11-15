
#include <iostream>


using namespace std;



class Block {

        public :

                // version of the block chain will use if want siwtch to proof of stak
                int32_t version;


                uint32_t   nonce;
                // this not good we need uint256 bcz we use sha256  . vector<unsigned cahr> 
                string     hash;

                string  PrevBlockHach ;

                uint32_t timestamp;
                

                


}