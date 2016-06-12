//
//  ViewController.m
//  FSwitch
//
//  Created by fengzifeng on 16/6/8.
//  Copyright © 2016年 fengzifeng. All rights reserved.
//

#import "ViewController.h"
#import "SwitchView.h"


@interface ViewController ()<UIScrollViewDelegate>
{
    NSArray *_sourseArray;
    
}
@property (strong, nonatomic) UIScrollView *scrollView;
@property (strong, nonatomic) SwitchView *switchView;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    _sourseArray = @[@"第一",@"第一个",@"第二",@"第二个",@"第三",@"第三个",@"第四",@"第四个",@"第五",@"第五个",@"第六"];
    
    [self.view addSubview:self.scrollView];
    [self.view addSubview:self.switchView];
}

- (UIScrollView *)scrollView
{
    if (!_scrollView) {
        _scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(0,44 + 64, SCREEN_WIDTH, SCREEN_HEIGHT - 44 - 64)];
        _scrollView.delegate = self;
        _scrollView.pagingEnabled = YES;
        _scrollView.scrollsToTop = NO;
        _scrollView.contentSize = CGSizeMake(SCREEN_WIDTH*_sourseArray.count, SCREEN_HEIGHT - 44 - 64);
        _scrollView.showsHorizontalScrollIndicator = NO;
        _scrollView.showsVerticalScrollIndicator = NO;
        
        for (int i = 0; i<_sourseArray.count; i++) {
            UIView *view = [[UIView alloc] initWithFrame:CGRectMake(SCREEN_WIDTH*i, 0, SCREEN_WIDTH, SCREEN_HEIGHT - 44 - 64)];
            view.backgroundColor = i%2?[UIColor yellowColor]:[UIColor whiteColor];
            
            [_scrollView addSubview:view];
        }
    }
    
    return _scrollView;
}

- (SwitchView *)switchView
{
    if (!_switchView) {
        _switchView = [[SwitchView alloc]initWithFrame:CGRectMake(0, 64, SCREEN_WIDTH, 44)];
        _switchView.titleArray = _sourseArray;
        __weak typeof (self.scrollView)weakScrollView = self.scrollView;
        
        [_switchView setTapItemWithIndex:^(NSInteger index,BOOL animation){
            [weakScrollView scrollRectToVisible:CGRectMake(index*weakScrollView.frame.size.width, 0.0, weakScrollView.frame.size.width,weakScrollView.frame.size.height) animated:animation];
        }];
    }
    
    return _switchView;
}

- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView{
    
    if (scrollView == self.scrollView) {
        NSInteger page = roundf(scrollView.contentOffset.x / scrollView.frame.size.width);
        page = MAX(page, 0);
        page = MIN(page, _sourseArray.count - 1);
        
        [_switchView endMoveToIndex:page];
    }
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}



@end
