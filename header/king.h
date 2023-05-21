class King : public Piece
{
    private:

    public:
        bool hasMoved();
        void move(vector<int> destination) override;
        vector<vector<int>> validDestinations() override;
};