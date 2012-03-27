/*
Copyright (C) 2012 MoSync AB

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License,
version 2, as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
MA 02110-1301, USA.
*/

/*! \addtogroup NativeUILib
 *  @{
 */

/**
 *  @defgroup NativeUILib Native UI Library
 *  @{
 */

/**
 * @file SegmentedListView.h
 * @author Bogdan Iusco
 *
 * @brief A SegmentedListView widget is used to present an indexed/grouped list
 * of items.
 * Available on iOS platform.
 */

#ifndef NATIVEUI_SEGMENTED_LIST_VIEW_H_
#define NATIVEUI_SEGMENTED_LIST_VIEW_H_

#include <NativeUI/Widget.h>

namespace NativeUI
{

	/**
	 * @brief Segmented list view types.
	 * Available on iOS platform.
	 */
	enum SegmentedListViewType
	{
		/**
		 * @brief Any section headers or footers are displayed as inline separators
		 * and float when the table view is scrolled.
		 */
		SegmentedListViewTypePlain = 0,
		/**
		 * @brief A table view whose sections present distinct groups of rows.
		 * The section headers and footers do not float.
		 */
		SegmentedListViewTypeGrouped
	};

	// Forward declaration
	class SegmentedListViewSection;

	/**
	 * @brief A SegmentedListView widget is used to present an indexed/grouped
	 * list of items.
	 * Only SegmentedListViewSection objects can be added to this list.
	 * Available on iOS platform.
	 */
	class SegmentedListView: public Widget
	{
	public:
		/**
		 * Constructor.
		 * @param listType Type of the list.
		 */
		SegmentedListView(
			SegmentedListViewType listType = SegmentedListViewTypePlain);

		/**
		 * Destructor.
		 */
		virtual ~SegmentedListView();

		/**
		 * Get the list type.
		 * @return One of the SegmentedListViewType values.
		 */
		SegmentedListViewType getType();

		/**
		 * Add a section to this list.
		 * @param section The section that will be added.
		 * The ownership of the section object is passed to this method.
		 */
		void addSection(SegmentedListViewSection* section);

		/**
		 * Reload list view data.
		 * Call this method after each modification done to list view data.
		 * Platform: iOS.
		 */
		void reloadData();

private:
		/**
		 * Add a widget as a child of this widget.
		 * @param widget The widget that will be added.
		 * The ownership of the widget is passed to this function.
		 * When the parent widget will be destroyed, all child widgets
		 * will be deleted.
		 * @return Any of the following result codes:
		 * - #MAW_RES_OK if the child could be added to the parent.
		 * - #MAW_RES_INVALID_HANDLE if any of the handles were invalid.
		 * - #MAW_RES_ERROR if it could not be added for some other reason.
		 */
		int addChild(Widget* widget);

		/**
		 * Insert a widget as a child of this widget, at a given position.
		 * @param widget The widget to be added.
		 * The ownership of the widget is passed to this function.
		 * When the parent widget will be destroyed, all child widgets
		 * will be deleted.
		 * @param index The position on which to add the child.
		 * @return Any of the following result codes:
		 * - #MAW_RES_OK if the child could be added to the parent.
		 * - #MAW_RES_INVALID_HANDLE if any of the handles were invalid.
		 * - #MAW_RES_INVALID_INDEX if the index was out of bounds.
		 * - #MAW_RES_ERROR if it could not be added for some other reason.
		 */
		int insertChild(Widget* widget, const int index);

		/**
		 * Remove a child widget from its parent (but does not destroy it).
		 * Removing a currently visible top-level widget causes the MoSync view
		 * to become visible.
		 * When the parent widget will be destroyed, the child widget will not
		 * be deleted.
		 * @param widget The widget to be removed.
		 * @return Any of the following result codes:
		 * - #MAW_RES_OK if the child could be removed from the parent.
		 * - #MAW_RES_INVALID_HANDLE if the handle was invalid.
		 * - #MAW_RES_ERROR otherwise.
		 */
		int removeChild(Widget* widget);
	};

} // namespace NativeUI

#endif /* NATIVEUI_SEGMENTED_LIST_VIEW_H_ */

/*! @} */
