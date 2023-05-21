class Bishop : public Piece
{
    private:

    public:
        void move(vector<int> destination) override;
        vector<vector<int>> validDestinations() override;
};