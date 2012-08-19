#include "wxcrafter.h"


// Declare the bitmap loading function
extern void wxC38D8InitBitmapResources();

static bool bBitmapLoaded = false;


SvnCommitDialogBaseClass::SvnCommitDialogBaseClass(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC38D8InitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer1 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer1);
    
    wxFlexGridSizer* flexGridSizer5 = new wxFlexGridSizer(  0, 2, 0, 0);
    flexGridSizer5->SetFlexibleDirection( wxBOTH );
    flexGridSizer5->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer5->AddGrowableCol(1);
    
    boxSizer1->Add(flexGridSizer5, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    m_staticText32 = new wxStaticText(this, wxID_ANY, _("Feature Request ID:"), wxDefaultPosition, wxSize(-1,-1), 0);
    flexGridSizer5->Add(m_staticText32, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_textCtrlFrID = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer5->Add(m_textCtrlFrID, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    m_staticTextBugID = new wxStaticText(this, wxID_ANY, _("Bug ID:"), wxDefaultPosition, wxSize(-1,-1), 0);
    flexGridSizer5->Add(m_staticTextBugID, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_textCtrlBugID = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer5->Add(m_textCtrlBugID, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    m_splitter1 = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxSP_LIVE_UPDATE|wxSP_3DSASH);
    m_splitter1->SetSashGravity(0.500000);
    m_splitter1->SetMinimumPaneSize(10);
    
    boxSizer1->Add(m_splitter1, 1, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    m_panel1 = new wxPanel(m_splitter1, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    
    wxBoxSizer* boxSizer15 = new wxBoxSizer(wxVERTICAL);
    m_panel1->SetSizer(boxSizer15);
    
    m_staticText17 = new wxStaticText(m_panel1, wxID_ANY, _("Modified Paths:"), wxDefaultPosition, wxSize(-1,-1), 0);
    boxSizer15->Add(m_staticText17, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    
    wxArrayString m_checkListFilesArr;
    m_checkListFiles = new wxCheckListBox(m_panel1, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), m_checkListFilesArr, wxLB_SINGLE);
    
    boxSizer15->Add(m_checkListFiles, 1, wxLEFT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    m_splitterPage14 = new wxPanel(m_splitter1, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_splitter1->SplitVertically(m_panel1, m_splitterPage14, 0);
    
    wxBoxSizer* boxSizer16 = new wxBoxSizer(wxVERTICAL);
    m_splitterPage14->SetSizer(boxSizer16);
    
    m_staticText19 = new wxStaticText(m_splitterPage14, wxID_ANY, _("Message:"), wxDefaultPosition, wxSize(-1,-1), 0);
    boxSizer16->Add(m_staticText19, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_textCtrlMessage = new wxTextCtrl(m_splitterPage14, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), wxTE_RICH2|wxTE_PROCESS_ENTER|wxTE_MULTILINE);
    wxFont m_textCtrlMessageFont = wxSystemSettings::GetFont(wxSYS_ANSI_FIXED_FONT);
    m_textCtrlMessage->SetFont(m_textCtrlMessageFont);
    
    boxSizer16->Add(m_textCtrlMessage, 1, wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    wxStaticBoxSizer* statixBoxSizer24 = new wxStaticBoxSizer( new wxStaticBox(this, wxID_ANY, _("Recent commit messages:")), wxVERTICAL);
    
    boxSizer1->Add(statixBoxSizer24, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    wxArrayString m_choiceMessagesArr;
    m_choiceMessages = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), m_choiceMessagesArr, 0);
    
    statixBoxSizer24->Add(m_choiceMessages, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxEXPAND, 5);
    
    wxBoxSizer* boxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    
    boxSizer1->Add(boxSizer2, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_button3 = new wxButton(this, wxID_OK, _("Commit"), wxDefaultPosition, wxSize(-1,-1), 0);
    m_button3->SetDefault();
    m_button3->SetToolTip(_("Commit"));
    
    boxSizer2->Add(m_button3, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM, 5);
    
    m_button4 = new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxSize(-1,-1), 0);
    
    boxSizer2->Add(m_button4, 0, wxLEFT|wxRIGHT|wxTOP|wxBOTTOM, 5);
    
    
    SetSizeHints(500,300);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre();
    // Connect events
}

SvnCommitDialogBaseClass::~SvnCommitDialogBaseClass()
{
}