#ifndef SALES_ASSOCIATE_H
#define SALES_ASSOCIATE_H


class Sales_Associate
{
    public:
		void Place_Order();
		void Print();
        void Report();
    private:
        string name;
        double total_sales;
};

#endif // SALES_ASSOCIATE_H
