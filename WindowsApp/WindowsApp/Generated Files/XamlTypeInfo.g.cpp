﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#include "pch.h"
#include "XamlTypeInfo.g.h"

#include "AnalysisPage.xaml.h"
#include "DiseaseTestPage.xaml.h"
#include "DocKitPage.xaml.h"
#include "MainMenu.xaml.h"
#include "MainPage.xaml.h"
#include "App.xaml.h"
#include "RecordPage.xaml.h"

#include "AnalysisPage.g.hpp"
#include "DiseaseTestPage.g.hpp"
#include "DocKitPage.g.hpp"
#include "MainMenu.g.hpp"
#include "MainPage.g.hpp"
#include "App.g.hpp"
#include "RecordPage.g.hpp"

::Platform::Collections::Vector<::Windows::UI::Xaml::Markup::IXamlMetadataProvider^>^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::OtherProviders::get()
{
    if(_otherProviders == nullptr)
    {
        _otherProviders = ref new ::Platform::Collections::Vector<::Windows::UI::Xaml::Markup::IXamlMetadataProvider^>();
    }
    return _otherProviders;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CheckOtherMetadataProvidersForName(::Platform::String^ typeName)
{
    ::Windows::UI::Xaml::Markup::IXamlType^ foundXamlType = nullptr;
    for (unsigned int i = 0; i < OtherProviders->Size; i++)
    {
        auto xamlType = OtherProviders->GetAt(i)->GetXamlType(typeName);
        if(xamlType != nullptr)
        {
            if(xamlType->IsConstructible)    // not Constructible means it might be a Return Type Stub
            {
                return xamlType;
            }
            foundXamlType = xamlType;
        }
    }
    return foundXamlType;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CheckOtherMetadataProvidersForType(::Windows::UI::Xaml::Interop::TypeName t)
{
    ::Windows::UI::Xaml::Markup::IXamlType^ foundXamlType = nullptr;
    for (unsigned int i = 0; i < OtherProviders->Size; i++)
    {
        auto xamlType = OtherProviders->GetAt(i)->GetXamlType(t);
        if(xamlType != nullptr)
        {
            if(xamlType->IsConstructible)    // not Constructible means it might be a Return Type Stub
            {
                return xamlType;
            }
            foundXamlType = xamlType;
        }
    }
    return foundXamlType;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CreateXamlType(::Platform::String^ typeName)
{
    if (typeName == L"Windows.UI.Xaml.Controls.Page")
    {
        return ref new XamlSystemBaseType(typeName);
    }

    if (typeName == L"Windows.UI.Xaml.Controls.UserControl")
    {
        return ref new XamlSystemBaseType(typeName);
    }

    if (typeName == L"Object")
    {
        return ref new XamlSystemBaseType(typeName);
    }

    if (typeName == L"String")
    {
        return ref new XamlSystemBaseType(typeName);
    }

    if (typeName == L"WindowsApp.AnalysisPage")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Windows.UI.Xaml.Controls.Page"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->Activator =
            []() -> Platform::Object^ 
            {
                return ref new ::WindowsApp::AnalysisPage(); 
            };
        userType->AddMemberName(L"NavigationHelper");
        userType->AddMemberName(L"DefaultViewModel");
        return userType;
    }

    if (typeName == L"WindowsApp.Common.NavigationHelper")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Object"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->AddMemberName(L"GoForwardCommand");
        userType->AddMemberName(L"GoBackCommand");
        userType->SetIsBindable();
        return userType;
    }

    if (typeName == L"Windows.Foundation.Collections.IObservableMap`2<String, Object>")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, nullptr);
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Metadata;
        userType->DictionaryAdd =
            [](Object^ instance, Object^ key, Object^ item) -> void
            {
                auto collection = (Windows::Foundation::Collections::IObservableMap<::Platform::String^, ::Platform::Object^>^)instance;
                auto newKey = (Platform::String^)key;
                auto newItem = (Platform::Object^)item;
                collection->Insert(newKey, newItem);
            };
        userType->SetIsReturnTypeStub();
        return userType;
    }

    if (typeName == L"WindowsApp.DiseaseTestPage")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Windows.UI.Xaml.Controls.Page"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->Activator =
            []() -> Platform::Object^ 
            {
                return ref new ::WindowsApp::DiseaseTestPage(); 
            };
        userType->AddMemberName(L"NavigationHelper");
        userType->AddMemberName(L"DefaultViewModel");
        return userType;
    }

    if (typeName == L"WindowsApp.DocKitPage")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Windows.UI.Xaml.Controls.Page"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->Activator =
            []() -> Platform::Object^ 
            {
                return ref new ::WindowsApp::DocKitPage(); 
            };
        userType->AddMemberName(L"NavigationHelper");
        userType->AddMemberName(L"DefaultViewModel");
        return userType;
    }

    if (typeName == L"WindowsApp.MainMenu")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Windows.UI.Xaml.Controls.Page"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->Activator =
            []() -> Platform::Object^ 
            {
                return ref new ::WindowsApp::MainMenu(); 
            };
        userType->AddMemberName(L"NavigationHelper");
        userType->AddMemberName(L"DefaultViewModel");
        return userType;
    }

    if (typeName == L"WindowsApp.MainPage")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Windows.UI.Xaml.Controls.Page"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->Activator =
            []() -> Platform::Object^ 
            {
                return ref new ::WindowsApp::MainPage(); 
            };
        userType->AddMemberName(L"NavigationHelper");
        userType->AddMemberName(L"DefaultViewModel");
        return userType;
    }

    if (typeName == L"WindowsApp.RecordPage")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Windows.UI.Xaml.Controls.Page"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->Activator =
            []() -> Platform::Object^ 
            {
                return ref new ::WindowsApp::RecordPage(); 
            };
        userType->AddMemberName(L"NavigationHelper");
        userType->AddMemberName(L"DefaultViewModel");
        return userType;
    }

    if (typeName == L"WindowsApp.Common.RelayCommand")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Object"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->SetIsReturnTypeStub();
        return userType;
    }

    return nullptr;
}

::Windows::UI::Xaml::Markup::IXamlMember^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CreateXamlMember(::Platform::String^ longMemberName)
{
    if (longMemberName == L"WindowsApp.AnalysisPage.NavigationHelper")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"NavigationHelper", L"WindowsApp.Common.NavigationHelper");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::WindowsApp::AnalysisPage^)instance;
                return that->NavigationHelper;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"WindowsApp.AnalysisPage.DefaultViewModel")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"DefaultViewModel", L"Windows.Foundation.Collections.IObservableMap`2<String, Object>");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::WindowsApp::AnalysisPage^)instance;
                return that->DefaultViewModel;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"WindowsApp.DiseaseTestPage.NavigationHelper")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"NavigationHelper", L"WindowsApp.Common.NavigationHelper");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::WindowsApp::DiseaseTestPage^)instance;
                return that->NavigationHelper;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"WindowsApp.DiseaseTestPage.DefaultViewModel")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"DefaultViewModel", L"Windows.Foundation.Collections.IObservableMap`2<String, Object>");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::WindowsApp::DiseaseTestPage^)instance;
                return that->DefaultViewModel;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"WindowsApp.DocKitPage.NavigationHelper")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"NavigationHelper", L"WindowsApp.Common.NavigationHelper");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::WindowsApp::DocKitPage^)instance;
                return that->NavigationHelper;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"WindowsApp.DocKitPage.DefaultViewModel")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"DefaultViewModel", L"Windows.Foundation.Collections.IObservableMap`2<String, Object>");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::WindowsApp::DocKitPage^)instance;
                return that->DefaultViewModel;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"WindowsApp.MainMenu.NavigationHelper")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"NavigationHelper", L"WindowsApp.Common.NavigationHelper");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::WindowsApp::MainMenu^)instance;
                return that->NavigationHelper;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"WindowsApp.MainMenu.DefaultViewModel")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"DefaultViewModel", L"Windows.Foundation.Collections.IObservableMap`2<String, Object>");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::WindowsApp::MainMenu^)instance;
                return that->DefaultViewModel;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"WindowsApp.MainPage.NavigationHelper")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"NavigationHelper", L"WindowsApp.Common.NavigationHelper");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::WindowsApp::MainPage^)instance;
                return that->NavigationHelper;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"WindowsApp.MainPage.DefaultViewModel")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"DefaultViewModel", L"Windows.Foundation.Collections.IObservableMap`2<String, Object>");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::WindowsApp::MainPage^)instance;
                return that->DefaultViewModel;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"WindowsApp.RecordPage.NavigationHelper")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"NavigationHelper", L"WindowsApp.Common.NavigationHelper");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::WindowsApp::RecordPage^)instance;
                return that->NavigationHelper;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"WindowsApp.RecordPage.DefaultViewModel")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"DefaultViewModel", L"Windows.Foundation.Collections.IObservableMap`2<String, Object>");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::WindowsApp::RecordPage^)instance;
                return that->DefaultViewModel;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"WindowsApp.Common.NavigationHelper.GoForwardCommand")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"GoForwardCommand", L"WindowsApp.Common.RelayCommand");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::WindowsApp::Common::NavigationHelper^)instance;
                return that->GoForwardCommand;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"WindowsApp.Common.NavigationHelper.GoBackCommand")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"GoBackCommand", L"WindowsApp.Common.RelayCommand");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::WindowsApp::Common::NavigationHelper^)instance;
                return that->GoBackCommand;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    return nullptr;
}
