//
//  MyClass.m
//  osx
//
//  Created by Elijah Insua on 7/28/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "WebGLView.h"

//#include "../../../src/WebGLRenderingContext.h"

@implementation WebGLView

- (id)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code here.
        //WebGLRenderingContext *context = new WebGLRenderingContext();
    }
    
    return self;
}

- (void)dealloc
{
    [super dealloc];
}

- (void)drawRect:(NSRect)dirtyRect
{
    // Drawing code here.
}

@end
