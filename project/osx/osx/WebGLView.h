//
//  MyClass.h
//  osx
//
//  Created by Elijah Insua on 7/28/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <QuartzCore/CVDisplayLink.h>

@interface WebGLView : NSOpenGLView {
    CVDisplayLinkRef displayLink;
}

@end
