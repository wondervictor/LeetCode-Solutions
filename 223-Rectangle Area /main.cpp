#include <iostream>


using namespace std;

class Solution {
public:

    class Solution {
    public:
        int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
            int width;
            int height;

            if(A >= G // rect1 is in the right of rect2
               || C <= E // rect1 is in the left of rect2
               || B >= H // rect1 is above rect2
               || D <= F // rect1 is below rect2
                    )
            {// no overlap
                width = 0;
                height = 0;
            }
            else
            {// overlap
                if(A <= E)
                    width = min(G - E, C - E);
                else
                    width = min(C - A, G - A);

                if(D <= H)
                    height = min(D - B, D - F);
                else
                    height = min(H - F, H - B);
            }
            return (C-A)*(D-B)+(G-E)*(H-F)-height*width;
        }
    };



    // stupid
    int computeArea1(int A, int B, int C, int D, int E, int F, int G, int H) {

        int whole = (G-E)*(H-F)+(C-A)*(D-B);

        if (C <= E || G <= A || B >= H || F >= D) {
            return whole;
        }

        if (A >= E && B >= F && C <= G && D <= H) {
//            int area = (C-A)*(D-B);
//            if (area == 0)
//                area = (G-E)*(H-F);
            return whole - min((G-E)*(H-F), (C-A)*(D-B));
        }
        if (E >= A && F >= B && G <= C && H <= D) {
//            int area = (G-E)*(H-F);
//            if (area == 0)
//                area = (C-A)*(D-B);
            return whole - min((G-E)*(H-F), (C-A)*(D-B));
        }

        if (D <= H) {
            int height = D-F;
            int width = 0;
            if(A <= E) {
                width = C-E;
            } else {
                width = G-A;
            }
            return whole - height * width;
        }

        if (H <= D) {
            int height = H - B;
            int width = 0;
            if(E <= A) {
                width = G-A;
            } else {
                width = C-E;
            }
            return whole - height * width;
        }

        return whole;

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}