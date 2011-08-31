//
//  webglstandalone_ipadAppDelegate.h
//  webglstandalone-ipad
//
//  Created by Elijah Insua on 8/30/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@class webglstandalone_ipadViewController;

@interface webglstandalone_ipadAppDelegate : NSObject <UIApplicationDelegate> {

}

@property (nonatomic, retain) IBOutlet UIWindow *window;

@property (nonatomic, retain) IBOutlet webglstandalone_ipadViewController *viewController;

@end
