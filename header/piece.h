#include <vector>
using namespace std;

class Piece
{
    private:
        char color;
        vector<int> position;

    public:
        virtual void move() = 0;
        virtual vector<vector<int>> validDestinations() = 0;
};

