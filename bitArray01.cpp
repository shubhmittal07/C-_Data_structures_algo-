#include <iostream>
#include <vector>
#define BYTE_BITS 8
#define BIT_TO_CHAR(bit) ((bit)/BYTE_BITS)
#define BIT_IN_CHAR(bit) (1 << (BYTE_BITS-1-((bit)%BYTE_BITS)))
#define MIN_CHARS(bits) ((((bits)-1)/CHAR_BIT)+1)
#define MAX_UCHAR 0xff
using namespace std;

class BitArray
{
    private:
        std::vector<unsigned char> m_bits;
        unsigned int m_totalBytes,m_totalBits;
    public:
        BitArray(unsigned int size)
        {
            m_totalBits = size;
            m_totalBytes = MIN_CHARS(m_totalBits);
            cout<<"Total number of Bytes: "<<m_totalBytes<<endl;
            m_bits.reserve(m_totalBytes);

            for(unsigned int i=0;i<m_totalBytes;i++)
            {
                m_bits.push_back(0);
            }
        }
        ~BitArray()
        {

        }
        void ClearAllBits()
        {
            m_bits.assign(m_bits.size(),0);
        }
        void SetAllBits()
        {
            m_bits.assign(m_bits.size(),MAX_UCHAR);
            int bits = m_totalBits % BYTE_BITS;

            if(bits!=0)
            {
                unsigned char mask = MAX_UCHAR << (BYTE_BITS - bits);
                m_bits[BIT_TO_CHAR(m_totalBits-1)] = mask; 
            }
        }

        void SetByte(unsigned int byte, unsigned char val)
        {
            m_bits[byte] = val;
        }
        void SetBit(unsigned int bit)
        {
            m_bits[BIT_TO_CHAR(bit)] |= BIT_IN_CHAR(bit);
        }
        void ClearBit(unsigned int bit)
        {
            unsigned char mask = BIT_IN_CHAR(bit);
            mask = ~mask;
            m_bits[BIT_TO_CHAR(bit)] &= mask;
        }
        bool operator[](unsigned int bit) const
        {
            cout<<"bit in char :"<<BIT_IN_CHAR(bit)<<endl;
            return((m_bits[BIT_TO_CHAR(bit)] &
            BIT_IN_CHAR(bit)) != 0);
        }
        
};
int main()
{
    BitArray bitArray(16);
    cout << "Bit Array Example" << endl;
    cout << "Data Structures for Game Developers" << endl;
    cout << "Allen Sherrod" << endl << endl;
    cout << "Initial bit values for 2, 3 and 14." << endl << endl;
    cout << "Bit 2 = " << bitArray[ 2] << "." << endl;
    cout << "Bit 3 = " << bitArray[ 3] << "." << endl;
    cout << "Bit 14 = " << bitArray[14] << "." << endl << endl;
    cout << "Set bits 2 and 14." << endl << endl;
    bitArray.SetBit(2);
    bitArray.SetBit(14);
    cout << "Bit 2 = " << bitArray[ 2] << "." << endl;
    cout << "Bit 3 = " << bitArray[ 3] << "." << endl;
    cout << "Bit 14 = " << bitArray[14] << "." << endl << endl;
    cout << "Set all bits" << endl << endl;
    bitArray.SetAllBits();
    cout << "Bit 2 = " << bitArray[ 2] << "." << endl;
    cout << "Bit 3 = " << bitArray[ 3] << "." << endl;
    cout << "Bit 14 = " << bitArray[14] << "." << endl << endl;
    cout << "Clear all bits" << endl << endl;
    bitArray.ClearAllBits();
    cout << "Bit 2 = " << bitArray[ 2] << "." << endl;
    cout << "Bit 3 = " << bitArray[ 3] << "." << endl;
    cout << "Bit 14 = " << bitArray[14] << "." << endl << endl;
    return 1;
}