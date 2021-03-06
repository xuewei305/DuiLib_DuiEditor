#ifndef __UIAccordionPane_H__
#define __UIAccordionPane_H__

#pragma once

namespace DuiLib
{
	#define	ACCORDION_ANIMATION_ID	1

	class UILIB_PLUGIN_API CAccordionPaneUI : public CVerticalLayoutUI, public CUIAnimation
	{
		DECLARE_DUICONTROL(CAccordionPaneUI)
		class CPaneCheckBox;
	public:
		CAccordionPaneUI();
		~CAccordionPaneUI();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);

		virtual void DoInit();

		virtual bool Activate();
		bool OnToggleEvent(void *param);
		virtual void DoEvent(TEventUI& event);
		void OnTimer( int nTimerID );
		virtual void OnAnimationStart(INT nAnimationID, BOOL bFirstLoop) {}
		virtual void OnAnimationStep(INT nTotalFrame, INT nCurFrame, INT nAnimationID);
		virtual void OnAnimationStop(INT nAnimationID);

		virtual SIZE EstimateSize(SIZE szAvailable);

		CControlUI* GetItemAt(int iIndex) const;
		int GetItemIndex(CControlUI* pControl) const;
		bool SetItemIndex(CControlUI* pControl, int iIndex);
		int GetCount() const;

		bool Add(CControlUI* pControl);
		bool AddAt(CControlUI* pControl, int iIndex);
		bool Remove(CControlUI* pControl);
		bool RemoveAt(int iIndex);
		void RemoveAll();

		CHorizontalLayoutUI *GetPaneHeader();
		CVerticalLayoutUI *GetPaneBody();

		void SetPaneVisible(bool bVisible, bool bAnimation = true);
		bool IsPaneVisible() const;
		virtual int GetFixedHeight() const;

		void SetFrameCount(int framecount);
		int GetFrameCount() const;
		void SetFrameDelay(int nDelay);
		int GetFrameDelay() const;

		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

	private:
		CHorizontalLayoutUI *m_pHeader;
		CLabelUI *m_pHeaderIcon;
		CLabelUI *m_pHeaderLabel;
		COptionUI *m_pHeaderButton;
		CVerticalLayoutUI	*m_pBody;

		int m_nHeaderHeight;
		int m_animation_direction; //动画方向 0 = 上下， 1=左右
		bool m_bPaneVisible;	

		RECT m_rcItemOld;

		int m_nFrameCount;
		int m_nFrameDelay;
	};

} // namespace DuiLib

#endif // __UIAccordionPane_H__