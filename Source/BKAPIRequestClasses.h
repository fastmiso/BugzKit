//
// BKAPIRequestClasses.h
//
// Copyright (c) 2009 Lukhnos D. Liu (http://lukhnos.org)
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//

#import "BKRequest.h"

@interface BKVersionCheckRequest : BKRequest
@end

@interface BKLogOnRequest : BKRequest
- (id)initWithAPIContext:(BKAPIContext *)inAPIContext accountName:(NSString *)inAccountName password:(NSString *)inPassword;
@end

@interface BKLogOffRequest : BKRequest
@end

extern NSString *const BKFilterList;
extern NSString *const BKProjectList;
extern NSString *const BKAreaList;
extern NSString *const BKCategoryList;
extern NSString *const BKPriorityList;
extern NSString *const BKPeopleList;
extern NSString *const BKStatusList;
extern NSString *const BKFixForList;
extern NSString *const BKMailboxList;

@interface BKListRequest : BKRequest
{
	NSString *listType;
}
- (id)initWithAPIContext:(BKAPIContext *)inAPIContext list:(NSString *)inListType writableItemsOnly:(BOOL)inListOnlyWritables;

@property (readonly) NSString *listType;
@property (readonly) NSArray *fetchedList;
@end

@interface BKAreaListRequest : BKListRequest
{
	NSUInteger projectID;	
}
- (id)initWithAPIContext:(BKAPIContext *)inAPIContext projectID:(NSUInteger)inProjectID writableItemsOnly:(BOOL)inListOnlyWritables;

@property NSUInteger projectID;
@end

@interface BKSetCurrentFilterRequest : BKRequest
{
	NSString *filterName;
}
- (id)initWithAPIContext:(BKAPIContext *)inAPIContext filterName:(NSString *)inFilterName;

@property (readonly) NSString *filterName;
@end

