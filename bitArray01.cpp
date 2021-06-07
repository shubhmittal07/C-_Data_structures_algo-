#include <iostream>
#include <vector>
#define BYTE_BITS 8
#define BIT_TO_CHAR(bit) ((bit)/BYTE_BITS)
#define BIT_IN_CHAR(bit) (1 << (BYTE_BITS-1-((bit)%BYTE_BITS)))
#define MIN_CHARS(bits) ((((bits)-1)/CHAR_BIT)+1)
#define MAX_UCHAR 0xff

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
        
};
int main()
{

}