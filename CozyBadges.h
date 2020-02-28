#define isIconInDock ([self.location isEqual:@"SBIconLocationDock"] || [self.location isEqual:@"SBIconLocationFloatingDock"] || [self.location isEqual:@"SBIconLocationFloatingDockSuggestions"])

@interface ColorBadges : NSObject
+ (instancetype)sharedInstance;
- (int)colorForIcon:(id)icon;
@end

@interface UIView (CozyBadges)
-(id)_viewControllerForAncestor;
@end

@interface SBRootFolderController : NSObject
-(id)dockIconListView;
@end

@interface SBFloatingDockViewController : NSObject
-(id)currentIconListView;
@end

@interface SBIcon : NSObject
@property (nonatomic,copy,readonly) NSString * applicationBundleID;
-(BOOL)isFolderIcon;
-(long long)badgeValue;
-(UIImage*)unmaskedIconImageWithInfo:(struct SBIconImageInfo)info;
@end

@interface SBLeafIcon : SBIcon
@end

@interface SBApplicationIcon : SBLeafIcon
@end

@interface SBFolder : NSObject
-(id)allIcons;
@end

@interface SBFolderIcon : SBIcon
@property (nonatomic,readonly) SBFolder * folder;
@end

@interface SBIconLabelImageParameters : NSObject
-(id)initWithParameters:(SBIconLabelImageParameters *)params;
@end

@interface _UILegibilitySettings : NSObject
@end

@interface _UILegibilityView : UIView
@property (nonatomic,retain) UIImageView * shadowImageView;
@property (nonatomic,retain) UIImage * shadowImage;
@property (nonatomic,retain) UIImageView * imageView;
@property (nonatomic,retain) UIImage * image;
@end

@interface SBIconLabelView : _UILegibilityView
-(void)updateIconLabelWithSettings:(id)arg1 imageParameters:(id)arg2;
@end

@interface SBIconView : UIView
@property (nonatomic,retain) SBIcon * icon;
@property (nonatomic,retain) _UILegibilitySettings * legibilitySettings;
@property (nonatomic,copy) NSString * location;
@property (nonatomic, retain) SBIconLabelView *labelView;
-(SBIconLabelImageParameters *)_labelImageParameters;
@end

@interface SBIconLegibilityLabelView : _UILegibilityView
@property (assign,nonatomic) SBIconView * iconView;
@end

@interface SBIconSimpleLabelView : UIImageView
@property (assign,nonatomic) SBIconView * iconView;
@end

@interface CBIconLabelImageParameters : SBIconLabelImageParameters
@property (nonatomic, retain) SBIcon *folderIcon;
@property (nonatomic, retain) SBIcon *icon;
@property (nonatomic, assign) BOOL hasNotification;
@property (nonatomic, retain) UIColor *dominantColor;
-(id)initWithParameters:(SBIconLabelImageParameters *)params icon:(SBIcon *)icon;
-(SBApplicationIcon *)iconForFolder:(SBIcon *)folderIcon;
-(UIColor *)focusHighlightColor;
@end

@interface SBIconLabelImage : UIImage
@end

@interface SBIconLabelImage (CozyBadges)
+(id)imageWithParameters:(id)arg1;
@end

@interface SBIconListView : UIView
-(NSArray *)icons;
-(void)setIconsNeedLayout;
@end

@interface SBDockIconListView : SBIconListView
@end

@interface SBFloatingDockController : NSObject
+(BOOL)isFloatingDockSupported;
@end

@interface SBIconController : UIViewController
+(id)sharedInstance;
-(BOOL)allowsBadgingForIcon:(id)arg1 ;
@end

typedef struct SBIconCoordinate {
    long long row;
    long long col;
} SBIconCoordinate;

typedef struct SBIconImageInfo {
    CGSize size;
    CGFloat optionA;
    CGFloat optionB;
} SBIconImageInfo;

static BOOL getBool(NSString *key);
static NSString* getValue(NSString *key);
