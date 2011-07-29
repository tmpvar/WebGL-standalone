//
//  webgl_standaloneAppDelegate.h
//  webgl-standalone
//
//  Created by Elijah Insua on 7/28/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface webgl_standaloneAppDelegate : NSObject <NSApplicationDelegate> {
@private
    NSWindow *window;
}

@property (assign) IBOutlet NSWindow *window;

@end
