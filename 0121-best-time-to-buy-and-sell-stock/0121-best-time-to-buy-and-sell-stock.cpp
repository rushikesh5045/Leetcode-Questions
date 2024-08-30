class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int least=INT_MAX;
       int overall=0;
       int todaysp =0;

       for(int i=0;i<prices.size();i++){
           if(prices[i]<least){
               least=prices[i];
           }
           todaysp=prices[i]-least;
           if(overall<todaysp){
               overall = todaysp;
           }
       }
       return overall; 
    }
};