/*-
*  Cross-Platform C++ Wrapper for Kiip
*  Designed to work with iOS and Android Kiip libraries
*  http://kiip.me
*  
*  Created by Brady Archambo (in no way affiliated with Kiip)
*
*  Find me on Twitter, twitter.com/bradyy
*
*/

#ifndef __KIIP_WRAPPER__
#define __KIIP_WRAPPER__

class KiipWrapper
{
public:
    static KiipWrapper* sharedKiipWrapper();
    
    void unlockAchievement(const char * name);
    void reportScoreForLeaderboard(const char * name, double score);
    
private:
    static KiipWrapper* m_spKiipWrapper;
};

#endif // __KIIP_WRAPPER__
