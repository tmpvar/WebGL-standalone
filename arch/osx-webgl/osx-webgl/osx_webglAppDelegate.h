//
//  osx_webglAppDelegate.h
//  osx-webgl
//
//  Created by Elijah Insua on 7/28/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface osx_webglAppDelegate : NSObject <NSApplicationDelegate> {
@private
    NSWindow *window;
}

@property (assign) IBOutlet NSWindow *window;

@end
