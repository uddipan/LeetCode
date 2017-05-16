class Solution {
public:
    double MO2(int a, int b)
    { return double( a + b ) / 2.0; }
    
    // A utility function to find median of three integers
    double MO3(int a, int b, int c)
    {
        return double(a + b + c - max(a, max(b, c))
                      - min(a, min(b, c)));
    }
    
    // A utility function to find median of four integers
    double MO4(int a, int b, int c, int d)
    {
        int Max = max( a, max( b, max( c, d ) ) );
        int Min = min( a, min( b, min( c, d ) ) );
        return double( a + b + c + d - Max - Min ) / 2.0;
    }
    
    // Utility function to find median of single array
    float median(vector<int> &A)
    {
        if (A.size() == 0)
            return -1;
        if (A.size()%2 == 0)
            return double(A[A.size()/2] + A[A.size()/2-1])/2.0;
        return double(A[A.size()/2]);
    }
    
    double helper(vector<int> &A, int szA, vector<int> &B, int szB)
    {
        // assume szA <= szB
        if(szA == 0)
        {
            return median(B);
        }
        
        if(szA == 1)
        {
            if(szB == 1)return MO2(A[0], B[0]);
            else if(szB & 1)
            {
                // Case 2: If the larger array has odd number of elements,
                // then consider the middle 3 elements of larger array and
                // the only element of smaller array.
                return MO2( B[szB/2], MO3(A[0], B[szB/2 - 1], B[szB/2 + 1]) );
            }
            else
            {
                // Case 3: If the larger array has even number of element,
                // then median will be one of the following 3 elements
                // ... The middle two elements of larger array
                // ... The only element of smaller array
                return MO3( B[szB/2], B[szB/2 - 1], A[0] );
            }
        }
        else if(szA == 2)
        {
            // Case 4: If the larger array also has two elements,
            // simply call MO4()
            if (szB == 2)
                return MO4(A[0], A[1], B[0], B[1]);
            
            // Case 5: If the larger array has odd number of elements,
            // then median will be one of the following 3 elements
            // 1. Middle element of larger array
            // 2. Max of first element of smaller array and element
            //    just before the middle in bigger array
            // 3. Min of second element of smaller array and element
            //    just after the middle in bigger array
            if (szB & 1)
                return MO3 ( B[szB/2], max(A[0], B[szB/2 - 1]),min(A[1], B[szB/2 + 1]));
            
            // Case 6: If the larger array has even number of elements,
            // then median will be one of the following 4 elements
            // 1) & 2) The middle two elements of larger array
            // 3) Max of first element of smaller array and element
            //    just before the first middle element in bigger array
            // 4. Min of second element of smaller array and element
            //    just after the second middle in bigger array
            return MO4 ( B[szB/2],B[szB/2 - 1],max( A[0], B[szB/2 - 2] ),min( A[1], B[szB/2 + 1] ));
        }
        
        int idxA = ( szA - 1 ) / 2;
        int idxB = ( szB - 1 ) / 2;
        
        if (A[idxA] <= B[idxB] )
        {
            vector<int>tmp(A.begin()+idxA,A.end());
            return helper(tmp, szA/2 + 1, B, szB - idxA );
        }
        
        vector<int>tmp(B.begin()+idxA,B.end());
        return helper(A, szA/2 + 1, tmp, szB - idxA );
    }
    
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return helper( nums2, nums2.size(), nums1, nums1.size() );
        
        return helper( nums1, nums1.size(), nums2, nums2.size() );
    }
};