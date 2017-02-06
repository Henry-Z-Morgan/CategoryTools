# MPMoviePlayerController
iOS 9之前，iOS播放视频文件一般使用 **MPMoviePlayerViewController** 和 **MPMoviePlayerController**。

前者继承自UIViewController，后者继承NSObject。MPMoviePlayerViewController里面包含了一个MPMoviePlayerController。

**要想使用上述两者，首先要包含 `#import头文件`和`MediaPlayer.framework`**

**iOS播放视频文件一般使用 MPMoviePlayerViewController 和 MPMoviePlayerController。这两者的区别就是MPMoviePlayerViewController里面包含了一个MPMoviePlayerController**
## 介绍MPMoviePlayerController
### 属性 
```   
// 播放媒体URL，这个URL可以是本地路径，也可以是网络路径
@property (nonatomic, copy) NSURL *contentURL

// 播放器视图，如果要显示视频必须将此视图添加到控制器视图中
@property (nonatomic, readonly) UIView *view 

// 播放器背景视图
@property (nonatomic, readonly) UIView *backgroundView

// 媒体播放状态
@property (nonatomic, readonly) MPMoviePlaybackState playbackState 
   枚举类型：   MPMoviePlaybackStateStopped：停止播放
              MPMoviePlaybackStatePlaying：正在播放
              MPMoviePlaybackStatePaused：暂停
              MPMoviePlaybackStateInterrupted：中断
              MPMoviePlaybackStateSeekingForward：向前定位
              MPMoviePlaybackStateSeekingBackward：向后定位
              
// 网络媒体加载状态 
@property (nonatomic, readonly) MPMovieLoadState loadState
   枚举类型：  MPMovieLoadStateUnknown：位置类型 
             MPMovieLoadStatePlayable：
             MPMovieLoadStatePlaythroughOK：这种状态如果shouldAutoPlay为YES将自动播放
             MPMovieLoadStateStalled：停滞状态
             
// 控制面板风格
@property (nonatomic) MPMovieControlStyle controlStyle
   枚举类型：  MPMovieControlStyleNone：无控制面板
             MPMovieControlStyleEmbedded：嵌入视频风格
             MPMovieControlStyleFullscreen：全屏
             MPMovieControlStyleDefault：默认风格

// 重复播放模式 
@property (nonatomic) MPMovieRepeatMode repeatMode;
   枚举类型:   MPMovieRepeatModeNone:不重复，默认值
             MPMovieRepeatModeOne:重复播放

// 当网络媒体缓存到一定数据时是否自动播放，默认为YES
@property (nonatomic) BOOL shouldAutoplay 	 

// 是否全屏展示，默认为NO，注意如果要通过此属性设置全屏必须在视图显示完成后设置，否则无效
@property (nonatomic, getter=isFullscreen) BOOL fullscreen 

// 视频缩放填充模式
@property (nonatomic) MPMovieScalingMode scalingMode  
   枚举类型：  MPMovieScalingModeNone：不进行任何缩放
             MPMovieScalingModeAspectFit：固定缩放比例并且尽量全部展示视频，不会裁切视频
             MPMovieScalingModeAspectFill：固定缩放比例并填充满整个视图展示，可能会裁切视频
             MPMovieScalingModeFill：不固定缩放比例压缩填充整个视图，视频不会被裁切但是比例失衡

// 是否有相关媒体被播放  
@property (nonatomic, readonly) BOOL readyForDisplay  

// 媒体类别
@property (nonatomic, readonly) MPMovieMediaTypeMask movieMediaTypes  
   枚举类型：  MPMovieMediaTypeMaskNone：未知类型
             MPMovieMediaTypeMaskVideo：视频
             MPMovieMediaTypeMaskAudio：音频

// 媒体源  
@property (nonatomic) MPMovieSourceType movieSourceType             
   枚举类型：  MPMovieSourceTypeUnknown：未知来源
             MPMovieSourceTypeFile：本地文件
             MPMovieSourceTypeStreaming：流媒体（直播或点播）
             
// 媒体时长，如果未知则返回0
@property (nonatomic, readonly) NSTimeInterval duration

// 媒体可播放时长，主要用于表示网络媒体已下载视频时长
@property (nonatomic, readonly) NSTimeInterval playableDuration 

// 视频实际尺寸，如果未知则返回CGSizeZero
@property (nonatomic, readonly) CGSize naturalSize 

// 起始播放时间
@property (nonatomic) NSTimeInterval initialPlaybackTime 

// 终止播放时间
@property (nonatomic) NSTimeInterval endPlaybackTime 

// 是否允许无线播放，默认为YES
@property (nonatomic) BOOL allowsAirPlay 	  

// 当前媒体是否正在通过AirPlay播放
@property (nonatomic, readonly, getter=isAirPlayVideoActive) BOOL airPlayVideoActive

// 是否准备好播放
@property(nonatomic, readonly) BOOL isPreparedToPlay  

// 当前播放时间，单位：秒
@property(nonatomic) NSTimeInterval currentPlaybackTime 

//当前播放速度，如果暂停则为0，正常速度为1.0，非0数据表示倍率
@property(nonatomic) float currentPlaybackRate   
```
### 对象方法  
```
// 使用指定的URL初始化媒体播放控制器对象
- (instancetype)initWithContentURL:(NSURL *)url                     

// 设置视频全屏，注意如果要通过此方法设置全屏则必须在其视图显示之后设置，否则无效
- (void)setFullscreen:(BOOL)fullscreen animated:(BOOL)animated 	

// 获取在指定播放时间的视频缩略图，
// playbackTimes   第一个参数是获取缩略图的时间点数组；
// option          第二个参数代表时间点精度,枚举类型
- (void)requestThumbnailImagesAtTimes:(NSArray *)playbackTimes timeOption:(MPMovieTimeOption)option 
   枚举类型：		MPMovieTimeOptionNearestKeyFrame：时间点附近
                   MPMovieTimeOptionExact：准确时间

// 取消所有缩略图获取请求
- (void)cancelAllThumbnailImageRequests 	

// 准备播放，加载视频数据到缓存，当调用play方法时如果没有准备好会自动调用此方法
- (void)prepareToPlay 	

// 开始播放
- (void)play 	

// 暂停播放
- (void)pause 	

// 停止播放
- (void)stop 	

// 向前定位
- (void)beginSeekingForward 	

// 向后定位
- (void)beginSeekingBackward 	

// 停止快进/快退
- (void)endSeeking 	
```
### 通知
```
// 视频缩放填充模式发生改变
MPMoviePlayerScalingModeDidChangeNotification 	

// 媒体播放完成或用户手动退出，具体完成原因可以通过通知userInfo中的key为
MPMoviePlayerPlaybackDidFinishNotification 	

// 的对象获取
MPMoviePlayerPlaybackDidFinishReasonUserInfoKey

// 播放状态改变，可配合playbakcState属性获取具体状态
MPMoviePlayerPlaybackStateDidChangeNotification 

// 媒体网络加载状态改变
MPMoviePlayerLoadStateDidChangeNotification

// 当前播放的媒体内容发生改变
MPMoviePlayerNowPlayingMovieDidChangeNotification

// 将要进入全屏
MPMoviePlayerWillEnterFullscreenNotification 	

// 进入全屏后
MPMoviePlayerDidEnterFullscreenNotification 	

// 将要退出全屏
MPMoviePlayerWillExitFullscreenNotification 	

// 退出全屏后
MPMoviePlayerDidExitFullscreenNotification 	

// 当媒体开始通过AirPlay播放或者结束AirPlay播放
MPMoviePlayerIsAirPlayVideoActiveDidChangeNotification

// 视频显示状态改变
MPMoviePlayerReadyForDisplayDidChangeNotification

// 确定了媒体可用类型后
MPMovieMediaTypesAvailableNotification 	

// 确定了媒体来源后
MPMovieSourceTypeAvailableNotification 	

// 确定了媒体播放时长后
MPMovieDurationAvailableNotification 	

// 确定了媒体的实际尺寸后
MPMovieNaturalSizeAvailableNotification 	

// 缩略图请求完成之后
MPMoviePlayerThumbnailImageRequestDidFinishNotification

// 做好播放准备后
MPMediaPlaybackIsPreparedToPlayDidChangeNotification
```


##### 首先要包含 #import <MediaPlayer/MediaPlayer.h>头文件和MediaPlayer.framework。
```
 - (void)createMPPlayerController:(NSString *)sFileNamePath {

  	NSURL *movieURL = [NSURL fileURLWithPath:sFileNamePath];

 	MPMoviePlayerController *movewController = [[MPMoviePlayerController alloc] initWithContentURL:movieURL];

	[movewController prepareToPlay];
	
    //设置写在添加之后   // 这里是addSubView
 	[self.view addSubview:movewController.view];

 	movewController.shouldAutoplay=YES;
 	
 	[movewController setControlStyle:MPMovieControlStyleDefault];
 	
 	[movewController setFullscreen:YES];
 	
 	[movewController.view setFrame:self.view.bounds];
 	
 	// 这里注册相关操作的通知

 	[[NSNotificationCenter defaultCenter] addObserver:self
                                          selector:@selector(movieFinishedCallback:)
                                          name:MPMoviePlayerPlaybackDidFinishNotification
                                          object:moveViewController.movewController]; //播放完后的通知
                                          
 	[movewController release];
}

-(void)movieFinishedCallback:(NSNotification*)notify {

    MPMoviePlayerController* theMovie = [notifyobject];

    [[NSNotificationCenterdefaultCenter] removeObserver:self
                                         name:MPMoviePlayerPlaybackDidFinishNotification
                                         object:theMovie];

    [theMovie.view removeFromSuperview];

    [theMovie release];

}
```

## 介绍下MPMoviePlayerViewController。 

**注意：MPMoviePlayerViewController 必须 presentMoviePlayerViewControllerAnimated方式添加，否则Done按钮是不会响应通知MPMoviePlayerPlaybackDidFinishNotification事件的；**

```
- (void)createMPPlayerController:(NSString *)sFileNamePath {
- 
  MPMoviePlayerViewController *moviePlayer =[[MPMoviePlayerViewControlleralloc] initWithContentURL:
                                                               [NSURLfileURLWithPath:sFileNamePath]];

    [moviePlayer.moviePlayerprepareToPlay];

    // 这里是presentMoviePlayerViewControllerAnimated
    [selfpresentMoviePlayerViewControllerAnimated:moviePlayer]; 

    [moviePlayer.moviePlayersetControlStyle:MPMovieControlStyleFullscreen];

    [moviePlayer.view setBackgroundColor:[UIColor clearColor]];

    [moviePlayer.view setFrame:self.view.bounds];

    [[NSNotificationCenterdefaultCenter] addObserver:self
                                         selector:@selector(movieFinishedCallback:)
                                         name:MPMoviePlayerPlaybackDidFinishNotification
                                         object:moviePlayer.moviePlayer];

    [moviePlayer release];

}

-(void)movieStateChangeCallback:(NSNotification*)notify  {

   //点击播放器中的播放/ 暂停按钮响应的通知

}

-(void)movieFinishedCallback:(NSNotification*)notify {

    // 视频播放完或者在presentMoviePlayerViewControllerAnimated下的Done按钮被点击响应的通知。
    MPMoviePlayerController* theMovie = [notifyobject];

    [[NSNotificationCenterdefaultCenter] removeObserver:self
                                         name:MPMoviePlayerPlaybackDidFinishNotification
                                         object:theMovie];

    [selfdismissMoviePlayerViewControllerAnimated];
}
```
```
以下是资料

 moviePlayer.moviewControlMode = MPMovieControlModeDefault;

 MPMovieControlModeDefault            显示播放/暂停、音量和时间控制

 MPMovieControlModeVolumeOnly         只显示音量控制

 MPMovieControlModeHidden             没有控制器

 
 moviePlayer.scallingMode = MPMovieScallingModeAspectFit;

 你可以使用下列宽高比值：

 MPMovieScallingModeNone            不做任何缩放

 MPMovieScallingModeAspectFit       适应屏幕大小，保持宽高比

 MPMovieScallingModeAspectFill      适应屏幕大小，保持宽高比，可裁剪

 MPMovieScallingModeFill            充满屏幕，不保持宽高比
 

 你会观察到以下通知：

 MPMoviePlayerContentPreloadDidFinishNotification
 当电影播放器结束对内容的预加载后发出。因为内容可以在仅加载了一部分的情况下播放，所以这个通知可能在已经播放后才发出。

 MPMoviePlayerScallingModeDidChangedNotification
 当用户改变了电影的缩放模式后发出。用户可以点触缩放图标，在全屏播放和窗口播放之间切换。

 MPMoviePlayerPlaybackDidFinishNotification
 当电影播放完毕或者用户按下了Done按钮后发出。
```

