/*******************************************************************************

Filename    :   Main.cpp
Content     :   Simple test app to test filter settings
Created     :
Authors     :   Federico Schliemann
Language    :   C++
Copyright:  Copyright (c) Facebook Technologies, LLC and its affiliates. All rights reserved.

*******************************************************************************/

#include <cstdint>
#include <cstdio>

#include "XrApp.h"

#include "Input/SkeletonRenderer.h"
#include "Input/ControllerRenderer.h"
#include "Input/TinyUI.h"
#include "Render/SimpleBeamRenderer.h"
class XrAppBaseApp : public OVRFW::XrApp {
   public:
    XrAppBaseApp() : OVRFW::XrApp() {
        ALOG("Constructor Initialized")
    }

    // Return a list of OpenXR extensions needed for this app
    virtual std::vector<const char*> GetExtensions() override {
        std::vector<const char*> extensions = XrApp::GetExtensions();

        // Add required extensions here:
        // extensions.push_back(XR_META_EXTENSION_NAME);
        return extensions;
    }

    // Must return true if the application initializes successfully.
    virtual bool AppInit(const xrJava* context) override {
        ALOG("App Initialized")
        if (!ui_.Init(context, GetFileSys())) {
            ALOG("TinyUI::Init FAILED.")
            return false;
        }
        /// Build UI
        label_ = ui_.AddLabel("Hello World!!!", {0, 0, 0}, {1300.0f, 100.0f});
        return true;
    }

    virtual void AppShutdown(const xrJava* context) override {
        OVRFW::XrApp::AppShutdown(context);
        ui_.Shutdown();
    }

    virtual void SessionEnd() override {
        ui_.Shutdown();
    }

    virtual bool SessionInit() override {
        ALOG("Session Initialized")
        /// Disable scene navigation
        GetScene().SetFootPos({0.0f, 0.0f, 0.0f});
        this->FreeMove = false;
        return true;
    }

    // Update state
    virtual void Update(const OVRFW::ovrApplFrameIn& in) override {
        ui_.Update(in);
        OVR::Posef headPose = in.HeadPose;
        OVR::Posef labelPose = OVR::Posef(headPose.Rotation, headPose.Transform(OVR::Vector3f(0, 0, -3)));
        label_->SetLocalPose(labelPose);
    }

    // Render eye buffers while running
    virtual void Render(const OVRFW::ovrApplFrameIn& in, OVRFW::ovrRendererOutput& out) override {
        /// Render UI
        ui_.Render(in, out);
    }

   private:
    OVRFW::TinyUI ui_;
    OVRFW::VRMenuObject* label_;
};

ENTRY_POINT(XrAppBaseApp)