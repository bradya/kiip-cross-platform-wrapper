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

#import "Kiip_ios.h"
#import "Kiip.h"

KiipWrapper* KiipWrapper::m_spKiipWrapper = NULL;

KiipWrapper* KiipWrapper::sharedKiipWrapper()
{
    if (m_spKiipWrapper == NULL) {
        m_spKiipWrapper = new KiipWrapper();
    }
    
    return m_spKiipWrapper;
}

void KiipWrapper::unlockAchievement(const char * name)
{
    NSString *achievementName = [NSString stringWithUTF8String:name];
    [[KPManager sharedManager] unlockAchievement:achievementName];
}

void KiipWrapper::reportScoreForLeaderboard(const char * name, double score)
{
    NSString *leaderboardName = [NSString stringWithUTF8String:name];
    [[KPManager sharedManager] updateScore:score onLeaderboard:leaderboardName];
}