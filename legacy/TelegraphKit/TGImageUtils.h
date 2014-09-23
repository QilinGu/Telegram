/*
 * This is the source code of Telegram for iOS v. 1.1
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Peter Iakovlev, 2013.
 */

#import <UIKit/UIKit.h>

#ifdef __cplusplus
extern "C" {
#endif
    
typedef enum {
    TGScaleImageFlipVerical = 1,
    TGScaleImageScaleOverlay = 2,
    TGScaleImageRoundCornersByOuterBounds = 4,
    TGScaleImageScaleSharper = 8
} TGScaleImageFlags;

UIImage *TGScaleImage(UIImage *image, CGSize size);
UIImage *TGScaleAndRoundCorners(UIImage *image, CGSize size, CGSize imageSize, int radius, UIImage *overlay, bool opaque, UIColor *backgroundColor);
UIImage *TGScaleAndRoundCornersWithOffset(UIImage *image, CGSize size, CGPoint offset, CGSize imageSize, int radius, UIImage *overlay, bool opaque, UIColor *backgroundColor);
UIImage *TGScaleAndRoundCornersWithOffsetAndFlags(UIImage *image, CGSize size, CGPoint offset, CGSize imageSize, int radius, UIImage *overlay, bool opaque, UIColor *backgroundColor, int flags);
    
inline bool TGEnableBlur() { return false; }
UIImage *TGScaleAndBlurImage(NSData *data, CGSize size, __autoreleasing NSData **blurredData);

UIImage *TGScaleImageToPixelSize(UIImage *image, CGSize size);
UIImage *TGRotateAndScaleImageToPixelSize(UIImage *image, CGSize size);

UIImage *TGFixOrientationAndCrop(UIImage *source, CGRect cropFrame, CGSize imageSize);
UIImage *TGRotateAndCrop(UIImage *source, CGRect cropFrame, CGSize imageSize);
    
UIImage *TGAttachmentImage(UIImage *source, CGSize sourceSize, CGSize size, bool incoming, bool location);
UIImage *TGSecretAttachmentImage(UIImage *source, CGSize sourceSize, CGSize size);
    
UIImage *TGIdenticonImage(NSData *data, CGSize size);
    
UIImage *TGCircleImage(CGFloat radius, UIColor *color);
    
#ifdef __cplusplus
}
#endif

@interface UIImage (Preloading)

- (UIImage *)preloadedImage;
- (void)tgPreload;

- (void)setMediumImage:(UIImage *)image;
- (UIImage *)mediumImage;

- (CGSize)screenSize;
- (CGSize)pixelSize;

@end

#ifdef __cplusplus
extern "C" {
#endif

CGSize TGFitSize(CGSize size, CGSize maxSize);
CGSize TGFillSize(CGSize size, CGSize maxSize);
CGSize TGCropSize(CGSize size, CGSize maxSize);
    
CGFloat TGRetinaFloor(CGFloat value);
    
bool TGIsRetina();
CGFloat TGScreenScaling();
bool TGIsPad();
    
CGSize TGScreenSize();
    
extern CGFloat TGRetinaPixel;

#ifdef __cplusplus
}
#endif