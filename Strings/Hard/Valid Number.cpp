class Solution
{
public:
bool isNumber(string s)
{
bool pose = false; //checking is it possible to put e or "E"
bool posp = true; // checking is it ok to poot "."
bool sign = true; //checking is it ok to put sign
bool ans = false; // just final ans
bool onee=true; // checking if there is already one or not if already it says false
if(s==".")
return ans;
for (auto a : s)
{
if (a >= '0' && a <= '9')
{
pose = true;
sign = false;
ans=true;
}
else if ((a == '-' || a == '+') && sign)
{
sign = false;
ans=false;
}
else if ((a == 'e' || a == 'E') && pose&&onee)
{
pose = false;
posp=false;
sign = true;
ans=false;
onee=false;
}
else if (a == '.' && posp)
{
posp = false;
sign=false;
}
else{
return false;
}
}
return ans;
}
};