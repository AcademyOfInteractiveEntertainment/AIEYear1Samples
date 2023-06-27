#pragma once

#include <vector>

#include "Vector3.h"
#include "Matrix3.h"

namespace aie
{
    class GameObject
    {
    protected:
        // The position of this object relative to its parent
        Vector3 LocalPosition;
        // The rotation of this object relative to its parent, in radians
        float LocalRotation;
        // The scale of this object relative to its parent
        Vector3 LocalScale;

        // Pointer to your parent (or nullptr if none)
        GameObject * Parent = nullptr;
        // Vector of children
        std::vector<GameObject *> Children;

        // Called when this specific object needs to update
        virtual void OnUpdate(float deltaTime);
        // Called when this specific object needs to draw to the screen
        virtual void OnDraw();

    public:
        GameObject();

        // Set a new parent for this object and/or unassign it from its parent
        void SetParent(GameObject * parent);
        // Get the current parent for this object
        GameObject * GetParent();
        // Get the current parent for this object - const-qualified
        const GameObject * GetParent() const;

        // Get a child at specific index from its vector of children
        GameObject * GetChild(size_t childIndex);
        // Get a child at specific index from its vector of children - const-qualified
        const GameObject * GetChild(size_t childIndex) const;

        // Get its local position relative to its parent
        Vector3 GetLocalPosition() const;
        // Set its local position relative to its parent
        void SetLocalPosition(Vector3 newPosition);
        // Set its local position relative to its parent
        void SetLocalPosition(float newX, float newY);

        // Get its world position
        Vector3 GetWorldPosition() const;

        // Get its local rotation relative to its parent
        float GetLocalRotation() const;
        // Set its local rotation relative to its parent
        void SetLocalRotation(float newRotation);

        // Get its world rotation
        float GetWorldRotation() const;

        // Get its local scale relative to its parent
        Vector3 GetLocalScale() const;
        // Set its local scale relative to its parent
        void SetLocalScale(Vector3 newScale);
        // Set its local scale relative to its parent
        void SetLocalScale(float newX, float newY);

        // Get its world scale
        Vector3 GetWorldScale() const;

        // Get the direction it is facing in world-space
        Vector3 GetForward() const;

        // Get its local transformation matrix
        Matrix3 GetLocalMatrix() const;
        // Get its world transformation matrix
        Matrix3 GetWorldMatrix() const;

        //
        // Transformations
        //

        // Move locally on X and Y axis - Z is untouched
        void Translate(float x, float y);
        // Move locally on X, Y, Z axes
        void Translate(Vector3 translation);

        // Rotate locally by given number of radians
        void Rotate(float radians);

        // Scale locally on X and Y axis - Z is untouched
        void Scale(float x, float y);
        // Scale locally on X, Y, Z axes
        void Scale(Vector3 scalar);

        //
        // Gameplay
        //

        // Updates this object and all of its children
        void Update(float deltaTime);
        // Draws this object and all of its children
        void Draw();

		//
		// OPTIONAL
		//

        void GetLocalTransform(Vector3 & localPos, float & localRot, Vector3 & localScl) const;
        void GetWorldTransform(Vector3 & worldPos, float & worldRot, Vector3 & worldScl) const;

		Matrix3 GetLocalToWorldMatrix() const;
	};
}