#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <cmath>
std::vector< int > loadTimeEstimator(std::vector< int > s, std::vector< int > t, int V) {
    typedef std::pair<double, int> pdi;
    typedef std::vector<int> vi;
    typedef std::vector<std::pair<double, int> > vdi;
    
    vdi times;
    for(int i = 0;i<t.size();i++)
    {
        times.push_back(pdi(t[i],i));
    }
    
    std::sort(times.begin(), times.end());
    
    double *timeElapseds = new double[t.size()];
    for(int i = 0;i<t.size();i++)
        timeElapseds[i] = 0;
    
    vdi works;
    for(int i = 0;i<times.size();i++)
    {
        double curTime = times[i].first;
        int curIdx = times[i].second;
        
        works.push_back(pdi(s[curIdx], curIdx));
        
        bool bEnd = i == times.size() - 1;
        
        if(!bEnd && std::fabs(curTime - times[i+1].first) < 1e-7)
            continue;
        
        sort(works.begin(), works.end());
        
        int n = (int)works.size();
        
        double lastTime = curTime + ((double)n / V) * works[works.size()-1].first;
        if(!bEnd)
            lastTime = std::min(lastTime, times[i+1].first);

        while(works.size() > 0)
        {
            double nextTime = lastTime;
            n = (int)works.size();
            
            vdi newWorks;
            for(int j = 0;j<works.size();j++)
            {
                double leftWork = works[j].first - (nextTime - curTime) * ((double)V / n);
                
                if(leftWork > 1e-7)
                {
                    newWorks.push_back(pdi(leftWork, works[j].second));
                    timeElapseds[works[j].second] += (nextTime - curTime);
                }
                else
                {
                    double timeElapsed = ((double)n / V) * works[j].first;
                    timeElapseds[works[j].second] += timeElapsed;
                    nextTime = curTime + timeElapsed;
                }
            }
            
            works = newWorks;
            curTime = nextTime;

            if(std::fabs(nextTime - lastTime) < 1e-7)
                break;
        }
    }
    
    vi rtn;
    for(int i = 0;i<t.size();i++)
    {
        rtn.push_back((int)(std::ceil(timeElapseds[i])) + t[i]);
    }
    
    return rtn;
}

int main()
{
//    std::vector<int> result = loadTimeEstimator({20,10}, {1,1}, 1);
    std::vector<int> result = loadTimeEstimator({1, 1, 1}, {10, 20, 30}, 3);
    for(int i = 0;i<result.size();i++)
    {
        std::cout << result[i] << std::endl;
    }
}

