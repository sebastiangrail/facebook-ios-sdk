/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <UIKit/UIKit.h>

#import <FBSDKCoreKit/FBSDKCoreKit.h>
#import <FBSDKShareKit/FBSDKShareMediaContent.h>
#import <FBSDKShareKit/FBSDKSharingValidation.h>

NS_ASSUME_NONNULL_BEGIN

@class PHAsset;

/**
 A photo for sharing.
 */
NS_SWIFT_NAME(SharePhoto)
@interface FBSDKSharePhoto : NSObject <NSSecureCoding, NSObject, FBSDKShareMedia, FBSDKSharingValidation>

/**
 Convenience method to build a new photo object with an image.
 @param image If the photo is resident in memory, this method supplies the data
 @param userGenerated Specifies whether the photo represented by the receiver was generated by the user or by the
 application
 */
+ (instancetype)photoWithImage:(UIImage *)image userGenerated:(BOOL)userGenerated;

/**
 Convenience method to build a new photo object with an imageURL.
 @param imageURL The URL to the photo
 @param userGenerated Specifies whether the photo represented by the receiver was generated by the user or by the
 application

 This method should only be used when adding photo content to open graph stories.
  For example, if you're trying to share a photo from the web by itself, download the image and use
  `photoWithImage:userGenerated:` instead.
 */
+ (instancetype)photoWithImageURL:(NSURL *)imageURL userGenerated:(BOOL)userGenerated;

/**
 Convenience method to build a new photo object with a PHAsset.
 - Parameter photoAsset: The PHAsset that represents the photo in the Photos library.
 - Parameter userGenerated: Specifies whether the photo represented by the receiver was generated by the user or by the
 application
 */
+ (instancetype)photoWithPhotoAsset:(PHAsset *)photoAsset userGenerated:(BOOL)userGenerated;

/**
 If the photo is resident in memory, this method supplies the data.
 @return UIImage representation of the photo
 */
@property (nullable, nonatomic, strong) UIImage *image;

/**
 The URL to the photo.
 @return URL that points to a network location or the location of the photo on disk
 */
@property (nullable, nonatomic, copy) NSURL *imageURL;

/**
 The representation of the photo in the Photos library.
 - Returns: PHAsset that represents the photo in the Photos library.
 */
@property (nullable, nonatomic, copy) PHAsset *photoAsset;

/**
 Specifies whether the photo represented by the receiver was generated by the user or by the application.
 @return YES if the photo is user-generated, otherwise NO
 */
@property (nonatomic, getter = isUserGenerated, assign) BOOL userGenerated;

/**
 The user generated caption for the photo. Note that the 'caption' must come from
 * the user, as pre-filled content is forbidden by the Platform Policies (2.3).
 @return the Photo's caption if exists else returns null.
 */
@property (nullable, nonatomic, copy) NSString *caption;

/**
 Compares the receiver to another photo.
 @param photo The other photo
 @return YES if the receiver's values are equal to the other photo's values; otherwise NO
 */
- (BOOL)isEqualToSharePhoto:(FBSDKSharePhoto *)photo;

@end

NS_ASSUME_NONNULL_END
