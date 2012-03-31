Cross-Platform C++ Wrapper for Kiip
===============
Call one method in your cross-platform code to unlock achievements and report leaderboard scores on both iOS and Android.

Android code uses the Android NDK.

Designed to work with iOS and Android Kiip libraries.

Works great with cocos2d-x! http://www.cocos2d-x.org/

Kiip can be found at http://kiip.me

If you have any feedback or find bugs, let me know. Find me on Twitter at http://twitter.com/bradyy or on Google+ at http://bradya.com


# Integration

1. Install the Kiip SDK in your platform-specific iOS and Android projects. For more information, check out Kiip's developer resources at http://kiip.me
1. Copy the wrapper's source files into your C++ project
2. Include KiipWrapper.h in the class where you would like to use Kiip


# Unlocking Achievements

1. Find out your achievement's unique id on Kiip's developer site
2. Call the following method in your code, passing in the achievement id

`KiipWrapper->sharedKiipWrapper()->unlockAchievement("achievementId")`


# Submitting Leaderboard Scores

1. Find out your leaderboard's unique id on Kiip's developer site
2. Call the following method in your code, passing in the leaderboard id and the score

`KiipWrapper->sharedKiipWrapper()->reportScoreForLeaderboard("leaderboardId", 1337)`