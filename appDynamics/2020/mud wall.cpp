int maxSeg(vector<int> pos, vector<int> height)
{
    int n=pos.size(), maxH=-1;
    for(int i=0;i<n-1;i++)
    {
        if(pos[i]<(pos[i+1]-1))
        {
            int gapLen=pos[i+1]-pos[i]-1;
            int heightDiff=height[i+1]-height[i];
            int lo=-1;
            if(gapLen>heightDiff)
            {
                int minHeight=max(height[i], height[i+1])+1;
                extraGap=gapLen-heightDiff-1;
                lo=minHeight+extraGap/2;
            }
            else
                lo=min(height[i], height[i+1]);
            maxH=(maxH, lo);
        }
    }
    return maxH;
}
