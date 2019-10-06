vector<int> zero(4);
vector<int> greedy(int price, int p, int q, int r, int s)
{
    if(price<=p)return {price, 0, 0, 0};
    price-=p;
    if(price <= 5*q)
    {
        if(price%5==0)return {p, price/5, 0, 0};
        return zero;
    }
    price-=q*5;
    if(price <= r*10)
    {
        if(price%10==0)return {p, q, price/10, 0};
        return zero;
    }
    price-=r*10;
    if(price <= s*25)
    {
        if(price%25==0)return {p, q, r, price/25};
        return zero;
    }
    return zero;
    
}
vector<int> maxCoin(int price, int p, int q, int r, int s)
{
    map<int, set<vector<int>>> mp;
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<=3;k++)
            {
                if(p>=i && q>=j && r>=k)
                {
                    auto nums=greedy(price, p-i, q-j, k-r, s);
                    if(nums!=zero)
                    {
                        int count=0;
                        for (int i = 0; i < 4; ++i)
                        {
                            count+=nums[i];
                        }
                        mp[-count].insert(nums);
                    }
                }
            }
        }
    }
    if(mp.empty())return zero;
    auto x=mp.begin()->second;
    if(x.empty())return zero;
    return (*x.begin());

}
